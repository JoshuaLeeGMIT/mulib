benchmark_incs = include_directories('../src/')

mulib_benchmark = shared_library('mulib-benchmark', mulib_src,
  include_directories: benchmark_incs,
  install: false
)

glib_dep = dependency('glib-2.0', version: '>= 2.55.0')
mu_dep = [
  declare_dependency(
    include_directories: benchmark_incs,
    link_with: mulib_benchmark
  )
]

gslist_benchmark = executable('gslist', 'benchmark-gslist.c',
  dependencies: glib_dep
)
mu_slist_benchmark = executable('slist', 'benchmark-mu-slist.c',
  dependencies: mu_dep
)

benchmark('gslist benchmark', gslist_benchmark)
benchmark('mu-list benchmark', mu_slist_benchmark)
