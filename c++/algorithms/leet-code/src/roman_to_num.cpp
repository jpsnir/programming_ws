#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, char * argv[]){
    std::string s = "MCMXCIV";
    const std::string order = "IVXLCDM";
    const vector<int> num_value = {1, 5, 10, 50, 100, 500, 1000};
    std::map <std::string, int> roman_setup {{"I",1}, {"V",5},
                                    {"X",10},
                                    {"L", 50},
                                    {"C",100},
                                    {"D",500},
                                    {"M",1000}
                                    };
    int number = 0;
    for (int i = 0; i < s.size();){ 
       if (order.find_first_of(s[i]) < order.find_first_of(s[i+1]) && i <
       s.size() - 1){
       cout << s[i] <<"," << s[i+1] << endl;
       cout << order.find_first_of(s[i]) << endl;
            if (s[i] == 'C'){
                if (s[i+1] == 'M')
                    number += 900;
                if (s[i+1] == 'D')
                    number += 400;
            }
            else if (s[i] == 'X'){
                if (s[i+1] == 'C')
                    number += 90;
                if (s[i+1] == 'L')
                    number += 40;
            }
            else if (s[i] == 'I'){
                if (s[i+1] == 'X')
                    number += 9;
                if (s[i+1] == 'V')
                    number += 4;
            }
            i = i + 2;
        }
        else{
        int entry = order.find_first_of(s[i]);
        number += num_value[entry];
        cout << " digit:"<<entry<<", number :"<< number << endl;
        i = i+1;
        }
    }
    cout << " Numeral is :" << number << endl;
}
