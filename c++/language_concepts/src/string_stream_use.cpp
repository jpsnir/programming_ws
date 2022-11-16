#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(){
    int c = 30;
    string sentence = "The C language is great to learn.";
    stringstream s(sentence);
    string word;
    while (s >> word)
        cout << word << endl;
    s.str("");
    s << c;
    cout << " string to number:" << s.str() ;
    return 0;
}
