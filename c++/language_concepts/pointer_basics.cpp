#include <iostream>
#include <cstdio>
#include <ostream>
#include <signal.h>

// show that with pointers we change the original values
// Different implementation of writing a function.
//
void add_pointer_based(int *a, int *b, int *c){
    *c = *a + *b;
    std::cout << "Address of a:" << a << std::endl;
    std::cout << "Address of b:" << b << std::endl;
    std::cout << "Address of c:" << c << std::endl;
}

int add_with_return(int *a, int *b){
    int c;
    std::cout << " Address of c:" << &c << std::endl;
    c = *a + *b;
    return c;
}


// This is an invalid function.
// gives a runtime error when executed.
int* add_with_return_pointer(int *a, int *b){
    int add;
    add =  *a + *b;
    return &add;
}

void sigsev_handler(int signo){
    printf("segmentation fault: %d - occured due to accessing stack memory that is deleted \n", signo);
    exit(1);
}

int main(void){
    signal(SIGSEGV, sigsev_handler);
    std::cout << " Hello, this is a primer on pointers" << std::endl;

    // https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/
    // 1. cover pointers and address
    //
    // a refers to address, v refers to value
    float f_v;
    float *f_a;
    f_v = 3.0f;
    f_a = &f_v;

    int *i_a, *i_b;
    int i_v, v2;
    i_v = 10;
    i_b = new int(i_v);
    i_a = &i_v;


    // Use printf %p specifier to display addresses
    printf("Address of i_a: %d - %p\n", i_v, i_a);
    printf("Address of f_a: %f - %p\n", f_v, f_a);
    std::cout << "f_v and i_v are on program stack memory" << std::endl;
    std::cout << " We can subtract value at the address \n";
    std::cout << " Difference of address " << *i_a - *f_a << std::endl;
    std::cout << " i_b sits on heap memory with address : " << i_b <<
        " and value " << *i_b << std::endl;
    // We cannot do arithmetic on pointers of different types.

    // 2. cover double pointer examples
    int **pp_a = &i_a;
    std::cout << "address of the double pointer pp_a : " << &pp_a << std::endl;
    std::cout << " You will notice that the pointers are also allocated on stack memory"
        << ". The difference between the addresses is the bytes required for each data type"<< std::endl;

    std::cout << " This shows the difference between the addresses of values assigned" << std::endl;
    std::cout << "Address of i_v as long integer: " << (long)i_a << std::endl;
    std::cout << "Address of f_v as long integer: " << (long)f_a << std::endl;
    std::cout << "pp_a as long integer: " << (long)pp_a << std::endl;
    // 3. cover function calls and return types with pointers
    int a = 10; int  b = 20; int  c;
    add_pointer_based(&a, &b, &c);
    std::cout << " The value of a " << a << " and address of a " << &a << std::endl;
    std::cout << " The value of b " << b << " and address of b " << &b << std::endl;
    std::cout << " The value of c " << c << " and address of c " << &c << std::endl;

    c = add_with_return(&a, &b);
    std::cout << " The value of c " << c << " and address of c " << &c << std::endl;

    int *pc;
    pc = add_with_return_pointer(&a, &b);
    std::cout << " The address obtained in pc: " << pc << std::endl;
    std::cout << " Accessing the value at pc address will give a segmentation fault" << std::endl;
    std::cout << " The value of pc " << *pc << std::endl;

    // 4. double pointers as multi-dimensional arrays; initializing 2d array
    //    with pointer approach
    int rows = 3;
    int cols = 3;
    int **matrix;



    // a. Multidimensional arrays with 2 indirections
    //
    // generate double pointers for each of the rows
    matrix = (int **)malloc(cols*rows*sizeof(int));


    // b. Multidimensional arrays with 1 indirection - contagious memory block
    if(matrix == NULL) {
        perror("Memory allocation failed");
        return 1;
    }


    // 5. Test for contiguous memory locations in a 1d - array, 2d array, etc.

    // 6. function pointers - https://www.geeksforgeeks.org/function-pointer-in-c/
    //
}
