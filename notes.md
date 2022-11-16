#Notes on programming


- About <unistd.h> - A header available in posix compliant systems and provides functions and definitions for unix OS. It is not part of standard c library in c++. One useful thing that it provides is the implementation of getopts and getopt_long() functions to command line arguments of the function.
- About <boost/filesystem.hpp> - A header file with file system operations, namespace : using namespace boost::filesystem
	* exists() - if a path exists
	* is_regular_file() - if the input is a regular file 
	* is_directory() - if the path is a directory
	* directory_iterator() - iterates over all the files in directory - 
			for (directory_entry& x : directory_iterator(p))
			for (auto&& x : directory_iterator(p)
- stringstream for parsing strings with functions - getline(stream_object,variable_to_assign,delimiter)
- fstream for parsing files withfunction - getline(stream_object,variable_to_assign)
- About <typeinfo>: has functions in c++ to tell the type of variable.

# Libraries
- GNU Scientific library - contains many math functions in C++ and C. 
