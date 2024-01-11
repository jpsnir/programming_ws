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

# pure virtual functions
1. interface: function without an implementation that must be overridden.
2. when it is not pure `virtual`, then it is the choice of the programmer to
   implement the same function in inherited class.
3. The interface class cannot be instantiated. as there is no implementation.

# visibility
1. `private` : cannot be accessed by inherited classes, or objects.
2. `protected`: can be accessed by inherited classes but not by objects.
3. `public` : can be accessed by anyone - inherited classes and by objects.
4. these access modifiers are just for maintaining code does not affect the
   performance of the code, provides the intent of the developer.
5.

# arrays
1. if we are allocating to location which is not part of the array, we may or
   may not get an error while compiling. It depends on the compiler settings.
2. put on heap, when the data needs to be supported for more lifetime.
3. Try to put on stack if you are bothered by the indirection using pointers
4. initialized to random values if unassigned - already existing on the memory
   addresses.
5. Determining the size of array using `sizeof` only works for arrays on stack.
   When arrays are passed in functions, we are actually passing pointers.
   For arrays on heap we neglect, it is not advised to use `sizeof` function
   as `new` operator returns pointers.
   So, to get size of arrays using `sizeof` is a bad practice and if you see
   that in code always modify that code.
6. Instead use `static const` variable to define the size, as array sizes need
   to be known at compile time and cannot be changed during the lifetime of
   program.
7. These are equivalent pass by pointer way for arrays.
    `void foo(int * x);`
    `void foo(int x[100]);`
    `void foo(int x[]);`
8. For passing by refernce in a function with an array, the syntax is `void
   foo(int (&x)[5])`. The size need to be declared in the pass by reference.
9. C character arrays are slightly different as they have `\0` termination and
   size need not be specified.

# strings
