pkg = import('pkgconfig')

api_version = '0.1'

mulib_src = files(
  'mu-arr.c',
  'mu-slist.c',
  'mu-str.c'
)

mulib_headers = [
  'mu-arr.h',
  'mu-slist.h',
  'mu-str.h'
]

version_split = meson.project_version().split('.')
MAJOR_VERSION = version_split[0]
MINOR_VERSION = version_split[1]
MICRO_VERSION = version_split[2]

version_conf = configuration_data()
version_conf.set('VERSION', meson.project_version())
version_conf.set('MAJOR_VERSION', MAJOR_VERSION)
version_conf.set('MINOR_VERSION', MINOR_VERSION)
version_conf.set('MICRO_VERSION', MICRO_VERSION)

mulib = shared_library('mulib-' + api_version,
  mulib_src,
  install: true,
)

install_headers(mulib_headers, subdir: 'mulib')

pkg.generate(
  description: 'A data structures library for C',
  libraries: mulib,
  name: 'mulib',
  filebase: 'mulib-' + api_version,
  version: meson.project_version(),
  subdirs: 'mulib',
  install_dir: join_paths(get_option('libdir'), 'pkgconfig')
)
