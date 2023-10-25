#include <iostream>
#include <stack>

// function call stack
// call by reference
void insert_at_stack_bottom(std::stack<int>& st, int x){
    //std::cout << " Reference of stack object:"<< &st << std::endl;
    if(st.empty()){
        st.push(x);
    }
    else {
        int top = st.top();
        st.pop();
        insert_at_stack_bottom(st, x);
        st.push(top);
    }
    std::cout << "insert at bottom recursion: \n";
    std::stack<int> st_copy = st;
    while(!st_copy.empty()){
        std::cout << st_copy.top() << "," ;
        st_copy.pop();
    }
    std::cout << "\n";

}

// This function gets the input stack to
// be reversed
void reverse_stack(std::stack<int> &st){
    if (!st.empty()){
        std::cout << "reverse stack recursion: \n";
        std::stack<int> st_copy = st;
        while(!st_copy.empty()){
            std::cout << st_copy.top() << "," ;
            st_copy.pop();
        }
        std::cout << "\n";
        int x = st.top();
        st.pop();
        reverse_stack(st);
        insert_at_stack_bottom(st, x);
    }
    return;
}

int main(){
    // define stack
    std::stack<int> st, st_copy;
    for (int i = 1; i <= 5; i++){
        st.push(i);
    }
    st_copy = st;
    std::cout << " Reference of original stack : " << &st << std::endl;
    std::cout << " Original " << std::endl;
    while(!st_copy.empty()){
        std::cout << st_copy.top() << ",";
        st_copy.pop();
    }
    std::cout << std::endl;

    reverse_stack(st);

    std::cout << " REVERSED " << std::endl;
    while(!st.empty()){
        std::cout << st.top() << "," ;
        st.pop();
    }
    std::cout << std::endl;

}
