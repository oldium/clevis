#define _GNU_SOURCE
#undef _FILE_OFFSET_BITS

#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <grp.h>
#include <string.h>
#include <limits.h>

#define TCSD_CONF "tcsd.conf"

int stat(const char *pathname, struct stat *statbuf) {
    static int (*real_stat)(const char *, struct stat *) = NULL;
    if (!real_stat) {
        real_stat = dlsym(RTLD_NEXT, "stat");
    }

    // Call the original stat function
    int result = real_stat(pathname, statbuf);
    if (result == 0) {
        size_t path_len = strlen(pathname);
        size_t tcsd_len = strlen(TCSD_CONF);
        if ((path_len >= tcsd_len)
                && (strcmp(pathname + path_len - tcsd_len, TCSD_CONF) == 0)
                && ((path_len == tcsd_len)
                    || (pathname[path_len - tcsd_len - 1] == '/'))) {

            statbuf->st_mode = 0640;
            statbuf->st_uid = 0;

            // Get the GID for the group 'tss'
            struct group *grp = getgrnam("tss");
            if (grp != NULL) {
                statbuf->st_gid = grp->gr_gid;
            }
            fprintf(stderr, "stat(%s) : simulate\n", pathname);
        } else {
            fprintf(stderr, "stat(%s) : passthrough\n", pathname);
        }
    }
    return result;
}

int setuid(uid_t uid) {
    return 0;
}

int setgid(gid_t gid) {
    return 0;
}

static void __attribute ((constructor))
set_line_buffering (void)
{
    setvbuf(stdout, NULL, _IOLBF, 0);
    fprintf(stderr, "set_line_buffering : done\n");
}
