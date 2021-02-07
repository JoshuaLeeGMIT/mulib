test_incs = include_directories('../src/')

mulib_test = shared_library('mulib-test', mulib_src,
  include_directories: test_incs,
  install: false
)

test_deps = declare_dependency(
  include_directories: test_incs,
  link_with: mulib_test
)

slist_test = executable('slist', 'test-slist.c',
  dependencies: test_deps
)

str_test = executable('str', 'test-str.c',
  dependencies: test_deps
)

test('mu-slist tests', slist_test)
test('mu-str tests', str_test)
