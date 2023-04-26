# setup.py

from distutils.core import setup, Extension
setup(name='sample',
      classifiers = ['Programming Language :: Python :: Implementation :: CPython'],
      headers = ['./sample.h'],
      ext_modules = [
        Extension('sample',
                  ['pysample.c'],
                  include_dirs=['./include'],
                  define_macros=[('FOO', '1')],
                  undef_macros=['BAR'],
                  library_dirs= ['./../build/c_extensions/'],
                  libraries = ['sample'],
                  )
        ]
      )
