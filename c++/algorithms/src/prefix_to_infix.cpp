/*
 * Program to convert prefix expression string to
 * postfix expression using a stack
 *
 * @author : jagatpreet
 * adapted from : geekfromgeeks
 */

#include <iostream>
#include <stack>
#include <string>

bool is_operator(char x){
    switch(x) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
            return true;
    }
    return false;
}

std::string prefix_to_infix(std::string pre_exp){
    std::stack<std::string> s;
    int length = pre_exp.size();

    for (int i = length -1; i >=0; i --){
        if(is_operator(pre_exp[i])){
            std::string op1 = s.top();
            s.pop();
            std::string op2 = s.top();
            s.pop();

            std::string temp = "(" + op1 + pre_exp[i] + op2 + ")";
            std::cout << " Pushing subexpression on top of stack: " << temp << std::endl;
            s.push(temp);
        }
        else {
            s.push(std::string(1, pre_exp[i]));
        }
    }
    return s.top();
}

int main() {
    std::string pre_exp = "*-A/BC-/AKL";
    std::string inf_exp =  prefix_to_infix(pre_exp);
    std::cout << " Final infix expression: " << inf_exp << std::endl;
    return 0;
}
