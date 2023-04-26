from distutisl.core import setup, Extension

setup(name='sample',
      classifiers = ['Programming Language :: Python :: Implementation :: CPython'],
      ext_modules = [
        Extension('sample',
                  ['pysample.c'],
                  include_dirs=['./include'],
                  define_macros=[('FOO', '1')],
                  undef_macros=['BAR'],
                  library_dirs= ['./build/'],
                  libraries = ['sample'],
                  )
        ]
      )
