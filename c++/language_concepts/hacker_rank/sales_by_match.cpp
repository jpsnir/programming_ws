//
// Created by jagatpreet on 6/8/21.
//

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char* argv[]){
    cout<<"Path:" << getenv("OUTPUT_PATH")<<endl;
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);
    cout<<"Entered string:"<<n_temp<<endl;
}