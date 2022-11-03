#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int a = 2;
  
  //stores an array of addresses in heap memory
  // This is done so we can easily delete the memory
  // after the program is about to end.
  // Heap memory need to be managed manually.
  vector<int*> ref_h;

 // loop allocates int objects in heap and gets the address
 // asssign it as array entries.
  for (int i = 0; i < 10; i++){
    ref_h.push_back(new int(i));
  }

  // Show that the heap memory is different for each new allocation
  // also show that the value assigned to each memory location in heap
  // is different.
  std::cout << "MEMORY ALLOCATED:" << std::endl;
  for (auto addr: ref_h){
    std::cout << " Reference address of memory:" << addr << std::endl;
    std::cout << " Value at the address : " << *addr << std::endl;
  }

  // delete heap memory
  std::cout << " \n Memory deletion started" << std::endl;
  for (auto addr: ref_h){
    delete addr; // deletes the int object from heap memory.
  }

  std:: cout << " Check after deleting" << std::endl;
  for (auto addr: ref_h){
    std::cout << " Reference address of memory:" << addr << std::endl;
    std::cout << " Value at the address:" << *addr << std::endl;
  }
  return 0;
}
