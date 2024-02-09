#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> tokens;
    stringstream ss(str);
    string token;
    while(getline(ss, token, ',')){
        tokens.push_back(stoi(token));
    }
    return tokens;
}

vector<string> parse_newlines(string str) {
	vector<string> tokens;
    stringstream ss(str);
    string token;
    while(getline(ss, token, '\n')){
        istringstream iss(token);
        cout << token << endl;
        cout << " Words parsing : " << endl;
        while(iss.good()){
            string word;
            getline(iss, word, ' ');
            cout << word << endl;
        }
        cout << "---------------" << endl;
        tokens.push_back(token);
    }
    return tokens;
}
vector<int> parse_integers(const string &s){
    stringstream ss(s);
    istringstream is(s);
    string token;
    int val;
    vector<int> output;
    while(std::getline(is, token, ',')){
        cout << token << endl;
    }

    while(getline(is, token, ',')){
        cout << token << endl;
        size_t size;
        output.push_back(std::stoi(token));
    }

    return output;

}
int main(){
    string str;
    cin >> str;
    vector<int> integers;
    integers = parse_integers(str);
    integers = parseInts(str);
    cout << "integers" << endl;
    for (auto v: integers){
        cout << v << endl;
    }
    string s = "My name is Jagatpreet.\n I am doing my PhD in computer engineering. \n I will finish it in 4 months.";
    parse_newlines(s);
}
