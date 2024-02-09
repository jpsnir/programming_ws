#include <iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;


void print(vector<string> &v){
    for (auto s : v){
        cout << s << endl;
    }
}

int main(){
    int lines, queries;
    string s;
    vector<string> hrml_doc;
    vector<string> hrml_queries;
    cin >> lines >> queries;
    // read all lines
    for(int i = 0; i < lines; i++){
        cin >> s ;
        hrml_doc.push_back(s);
    }
    for(int i = 0; i < queries; i++){
        cin >> s ;
        hrml_queries.push_back(s);
    }

    // check document:
    print(hrml_doc);
    print(hrml_queries);

}
