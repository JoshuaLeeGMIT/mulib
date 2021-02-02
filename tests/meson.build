test_incs = include_directories('../src/')

mulib_test = shared_library('mulib-test', mulib_src,
  include_directories: test_incs,
  install: false
)

test_deps = declare_dependency(
  include_directories: test_incs,
  link_with: mulib_test
)

str_test = executable('str', 'test-str.c',
  dependencies: test_deps
)

test('mu-str tests', str_test)
