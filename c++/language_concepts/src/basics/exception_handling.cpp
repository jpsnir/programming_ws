#include <exception>
#include<stdexcept>
#include <iostream>
#include <sstream>

// stdexcept defines many std exceptions that are implemented from
// exception class. - std::logic_error, std::out_of_range,
// exception header contains the std::exception base class.
// https://stackoverflow.com/questions/25163105/stdexcept-vs-exception-headers-in-c
// They are in separte headers, stdexcept headers already includes exceptions.
// But when you want to define custom exception that inherits from exception
// you need only the exception class.

using namespace std;
class Test{
    public:
        Test(){
            cout << " Test created" << endl;
        }
        ~Test(){
            cout << " Test destroyed" << endl;
        }
};
int main(int argc, char* argv[]){
        if (argc !=3){
            cout << " exception handling numerator denominator" << endl;
            exit(0);
        }
        int numerator = std::stoi(*(argv + 1));
        int denominator = std::stoi(*(argv + 2));
        float res;
    try{
        if (denominator == 0){
            throw runtime_error("Division by zero is not allowed");
        }

        res = (float)numerator/denominator;
        cout << " Result = " << res << endl;
    }
    catch(const exception& e){
        cerr <<"Exception " << e.what() <<endl;
    }
    catch(...){

        cout << " I catch all exceptions " << endl;
    }

    // scenario 2
    // you can throw exceptions of any intrinsic types,
    // but to catch those we need to have similar catch statements
    // with same type.
    // Also see the use of catch(...) to catch anything
    try{
        if (denominator == 0)
            throw -1;
    }
    catch (char c){
        cout << " I catch char exceptions" << endl;
    }
    catch (int n){
        cout << " I catch int exceptions: " << n << endl;
    }
    // can be used in very critical situations where the system is not yet
    // completely known and under test. This reflects lack of knowledge of the
    // system.
    catch(...){
        cout << " I catch all exceptions" << endl;
    }

    // scenario 3:
    // This scenarios show cases that any object that are declared within the
    // try block are destroyed on stack before catch statements are executed.
    // This is important to know as it can lead to memory leaks and also cause
    // other problems.
    //
    //

    Test t_out;
    Test* t_ptr;
    try{
        // test declared in scope of try will be destroyed
        Test t;
        auto ptr = new Test();
        // just to prevent memory leak we store it in another variable
        // ptr will be destroyed as a pointer but the object on heap will not be
        t_ptr = ptr;
        throw runtime_error("Failed exceuction");
    }
    catch(exception e){
        cout << e.what() << endl;
    }
    cout << " End of program" << endl;
    delete t_ptr;
    return 0;
}
