#include <iostream>
#include <stack>

void implement_stack();

int main(int argc, char* argv[]){
    implement_stack();
}

/* Stack in STL is a template container
 * We can use any data type to store that as stack.
 * This example uses integers
 */
void implement_stack(){
    std::stack<int> integer_stack;
    int arr[4] = {21, 24, 98, 45};
    for (auto &e : arr){
        std::cout << " Pushing " << e << " to stack" << std::endl;
        integer_stack.push(e);
    }

    std::cout << " Top of stack: " << integer_stack.top() << std::endl;

    int number_of_pops = 2;
    for (int i=0; i<number_of_pops; i++){
        std::cout << "Popping the top element, iteration : " << i << std::endl;
        // Pop only when non empty
        if (!integer_stack.empty()){
            integer_stack.pop();
        }
        else{
            std::cout << "stack is empty now" << std::endl;
            break;
        }
    }
    std::cout << " Top of stack: " << integer_stack.top() << std::endl;
}
