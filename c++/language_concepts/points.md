#cherno
1. function declaration is necessary but can be done only once.
2. header files help us to get the declaration in all files that use the
   function.
3. preprocesser directives - begins with `#`- compiler copies the files the header files in cpp
   files.
4. `#pragma once` include the header file only once in the .cpp file. - header
   guard.
5. `include <>` does not mean relative to the current directory
6. `include "" ` is always relative path.

# destructor
1. when the object is destroyed or deleted, this is called `~ClassName`.
2. For stack based objects, it is automatically called
3. For heap based objects (using `new`), it has to be deleted using `delete` keyword

# inheritance
1. common code in base class
2. prevents code duplication
3. common code to be put in a single class so we dont repeat
4. we can access all the public attributes and methods of the base class in
   inherited class.
5. About types: The object created is both types. base and inherited.
6. Subclassses are supersets of base classes.
7. if we are overriding functions, the size of the classes may vary.

# virtual functions
1. dynamic dispatch to map to the correct object.
2. adding `virtual` we can generate vlookup table which is accessed dynamically.
3. mark `override` in the inherited class.
4. cost of : storing virtual functions as vtables.
5. run-time cost associated with finding out which functions to run from the
   base class. Each base class will have its vtable for virtual functions.

#pure virtual functions
1. interface: function without an implementation that must be overridden.
2. when it is not pure `virtual`, then it is the choice of the programmer to
   implement the same function in inherited class.
3. The interface class cannot be instantiated. as there is no implementation.
