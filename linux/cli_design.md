# command line design guidelines

-[POSIX utilities
guidelines](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html)
- [GNU coding
    conventions](https://www.gnu.org/prep/standards/standards.html#Command_002dLine-Interfaces)
- [stackexchange  - good habits for designing
    cli](https://softwareengineering.stackexchange.com/questions/307467/what-are-good-habits-for-designing-command-line-arguments)
- mimic the behavior of popular programs - cmake, git 
    - `-n` -> dry run
    - `-v` -> verbosity
    -
- often use `-` for standard input or output
- In some cases, embed an interpreter like GNU guile or Lua in
  your software. 

- library similar to argparse - [tclap](https://github.com/mirror/tclap.git)
- [getopt
    library](https://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html)

