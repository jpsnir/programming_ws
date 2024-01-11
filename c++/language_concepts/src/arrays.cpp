#include <iostream>
#include <array>

// looks like pass by value, but we are passing pointers
void add_array(int arr[]){
    std::cout << "Array is a pointer here: look at the size: " << sizeof(arr) << std::endl;
    for (int i = 0; i < 5; i ++){
        arr[i] = 10;
    }
}

// treating array as pointer object
void add_array_1(int* arr){
    // get a pointer and then use indirection to assign at
    // that address.
    for (int i = 0; i < 5; i ++){
        *(arr + i) = 11;
    }

}
void add_array_2(int* arr){
    for (int i = 0; i < 5; i ++){
         arr[i] = 12;
    }
}
// can we pass by reference
void add_array_3(int (&arr)[5]){
    std::cout << "Array size when passed by reference " << sizeof(arr) << std::endl;
    for (int i = 0; i < 5; i ++){
        arr[i] = 13;
    }
}

int main(){
    // array declaration
    int example[5];

    int *heap_array = new int(5);
    // example is a pointeir
    std::cout << " Size of stack array = " << sizeof(example)/sizeof(int) << std::endl;
    std::cout << " Size of heap array = " << sizeof(heap_array)/sizeof(int) << std::endl;
    std::cout << " Size of int pointer = " << sizeof(int*) << std::endl;
    std::cout << " Heap array size is size of pointer/ size of int. Therefore this method is not"<<
              "trustworthy for calculating the size" << std::endl;


    std::cout << " --------------Unintialized ------------------- " << std::endl;
    for (int i = 0; i < 5; i++){
        std::cout << " element : " << example[i] << std::endl;
    }

    std::cout << " ----------------function pass by array pointer------------------ " << std::endl;
    add_array(example);

    for (int i = 0; i < 5; i++){
        std::cout << " element : " << example[i] << std::endl;
    }

    std::cout << " ---------------- function pass by pointer - 1 ------------ " << std::endl;
    add_array_1(example);
    for (int i = 0; i < 5; i++){
        std::cout << " element : " << example[i] << std::endl;
    }
    std::cout << " ---------------- function pass by pointer - 2 ------------ " << std::endl;
    add_array_2(example);
    for (int i = 0; i < 5; i++){
        std::cout << " element : " << example[i] << std::endl;
    }
    std::cout << " ------------- function pass by reference -------- " << std::endl;
    add_array_3(example);
    for (int i = 0; i < 5; i++){
        std::cout << " element : " << example[i] << std::endl;
    }

    delete heap_array;

    return 0;
}
