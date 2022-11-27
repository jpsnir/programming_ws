#include <chrono>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <thread>
#include <unistd.h> // unix standard library

class ThreadCallback {
public:
  void threadCallbackfunc() {
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    std::cout << "Hello from object member thread: " << std::this_thread::get_id()
              << std::endl;
  }

  static void threadCallbackfunc1() {
    std::cout << " Hello from the static method : "
              << std::this_thread::get_id() << std::endl;
  }

  void operator()() {
    std::cout << "Hello from class operator callable thread: "
              << std::this_thread::get_id() << std::endl;
  }
};

void func_thread_callback() {
  std::string s = "Hello from a function thread";
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  std::cout << s << ":thread id - " << std::this_thread::get_id() << std::endl;
  std::cout << " function thread finished " << std::endl;
}

void main_thread_method() {
  std::stringstream ss;
  std::string s = "Hello from main thread";
  for (char c : s) {
    ss << c;
    // best to use this as it has units.
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
  ss << ": thread id: " << std::this_thread::get_id();
  std::cout << ss.str() << std::endl;
  std::cout << " main thread finished " << std ::endl;
}

int main() {
  auto start = std::chrono::steady_clock::now();
  std::thread func_thread(func_thread_callback); // simulates another process.
  // Object on Heap memory
  // we need to delete this object - otherwise there can be memory leaks
  ThreadCallback *tCallbackObjPtr = new ThreadCallback();
  // The syntax for thread is thread(&func, &arg1, &arg2). For object member
  // functions, the first function argument is always `this` ( pointer to the
  // current object. This is generally done by compiler. But in this case, we
  // need to explicitly specify the pointer to the object. 
  std::thread obj_method_thread1(&ThreadCallback::threadCallbackfunc,
                                 tCallbackObjPtr);

  // Object on heap memory, with RAII style smart pointer
  std::unique_ptr<ThreadCallback> tSmartPtr =
      std::make_unique<ThreadCallback>();
  std::thread obj_method_thread3(&ThreadCallback::threadCallbackfunc, 
                                  tSmartPtr.get());
  
  // Object on stack, do this only when resource usage of the class is not huge.
  ThreadCallback tCallbackObj;

  std::thread class_operator_thread(tCallbackObj);


  std::thread obj_method_thread2(&ThreadCallback::threadCallbackfunc,
                                 &tCallbackObj);


  std::thread static_method_thread(&ThreadCallback::threadCallbackfunc1);


  main_thread_method(); // simulates some process for few seconds

  // this ensures that the main thread will wait before exiting.i

  if (func_thread.joinable())
    func_thread.join();
  delete tCallbackObjPtr;
  obj_method_thread1.join();
  obj_method_thread3.join();

  obj_method_thread2.join();
  class_operator_thread.join();
  static_method_thread.join();

  // Donot delete this befor joining the associated object thread.
 
  return EXIT_SUCCESS;
}
