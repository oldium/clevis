# Tests.
env = environment()
env.prepend('PATH',
  join_paths(meson.source_root(), 'src'),
  join_paths(meson.source_root(), 'src', 'luks'),
  join_paths(meson.source_root(), 'src', 'luks', 'tests'),
  join_paths(meson.source_root(), 'src', 'pins', 'sss'),
  join_paths(meson.source_root(), 'src', 'pins', 'tang'),
  join_paths(meson.source_root(), 'src', 'pins', 'tpm2'),
  join_paths(meson.source_root(), 'src', 'pins', 'tpm2', 'tests'),
  join_paths(meson.build_root(), 'src'),
  join_paths(meson.build_root(), 'src', 'luks'),
  join_paths(meson.build_root(), 'src', 'luks', 'tests'),
  join_paths(meson.build_root(), 'src', 'pins', 'sss'),
  join_paths(meson.build_root(), 'src', 'pins', 'tang'),
  join_paths(meson.build_root(), 'src', 'pins', 'tpm2'),
  join_paths(meson.build_root(), 'src', 'pins', 'tpm2', 'tests'),
  separator: ':'
)
test('pin-tpm2-hw', find_program('pin-tpm2-hw'), env: env, timeout: 120)
test('pin-tpm2-sw', find_program('pin-tpm2-sw'), env: env, timeout: 120)
