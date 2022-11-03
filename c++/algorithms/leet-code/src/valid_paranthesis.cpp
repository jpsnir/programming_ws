#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool isvalid(string s) {
  /*
  1. The string has to be even numbered in length, all odd numbered sized
  strings are invalid Implement stack
  1. All left brackets will fill up stack, and all right brackets will clear up
  stack.
  2. Top of the stack can be cleared only with the matching bracket.

  1. Initialize empty stack (list, queue, vector)
  2. if c == '(' or c == '{' c == '[' - append last element
  3. if c == ')' or c == '}' c == ']' -
  3.1 check last element if matches then remove element
  3.2 if element does not match, terminate return false

  4. continue until end of string, stack size should be zero.

  No. of iterations: N (length of string);
  */

  if (s.size() % 2 != 0) {
    return false;
  }
  stack<char> brackets;
  for (auto c : s) {
    if (brackets.empty() && (c == ')' || c == '}' || c == ']')){
        return false;

    }
        
    if (c == '(' || c == '{' || c == '['){
      brackets.push(c);
    }
    else {
      if ((brackets.top() == '(' && c == ')') ||
          (brackets.top() == '{' && c == '}') ||
          (brackets.top() == '[' && c == ']')) {
        brackets.pop();
      } else {
        break;
      }
    }
  }
  cout << " stack size: " << brackets.empty() << std::endl;
  if (brackets.empty())
    return true;
  else 
    return false;
}
  int main(int argc, char *argv[]) {
    if (argc != 2) {
      std::cout << " Usage : ./valid_paranthesis <string> " << std::endl;
      return 0;
    }
    string s = *(argv + 1);
    std::cout << " Input string: " << s << std::endl;
    bool valid = isvalid(s);
    string result = valid ? "string is valid" : " string is invalid";
    std::cout << result << std::endl;
  }
