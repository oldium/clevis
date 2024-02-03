# Tests
env = environment()
env.prepend('PATH',
  join_paths(meson.source_root(), 'src'),
  join_paths(meson.source_root(), 'src', 'pins', 'tpm1'),
  join_paths(meson.source_root(), 'src', 'pins', 'tpm1', 'tests'),
  join_paths(meson.build_root(), 'src'),
  join_paths(meson.build_root(), 'src', 'luks', 'tests'),
  join_paths(meson.build_root(), 'src', 'pins', 'tang', 'tests'),
  join_paths(meson.build_root(), 'src', 'pins', 'tpm1'),
  join_paths(meson.build_root(), 'src', 'pins', 'tpm1', 'tests'),
  separator: ':'
)

libdl_dep = dependency('dl', required : true)
tcsd_patch = shared_library('tcsd-patch', 'tcsd-patch.c',
  dependencies: libdl_dep,
  c_args: ['-fPIC', '-Wall', '-Wextra'],
  install: false)
tcsd_patch_path = tcsd_patch.full_path()
env.prepend('TCSD_PATCH_LIB', tcsd_patch_path)

test('pin-tpm1-hw', find_program('pin-tpm1-hw'), env: env, timeout: 120)
test('pin-tpm1-sw', find_program('pin-tpm1-sw'), env: env, timeout: 120)
