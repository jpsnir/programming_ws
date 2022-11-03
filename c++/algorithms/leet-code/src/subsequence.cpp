#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]){
    vector<std::string> strings = {"ch","rt","act","ers"};
    std::cout << "array of strings are:"<<std::endl;
    std::cout<<"match: "<< strings[1].find_first_of(strings[3]) << std::endl;
    for (auto s : strings)
        std::cout<<s<<",";
    std::cout<<"\n";
    std::string current;
    int max_subseq_length = 0;
    vector<vector<int>> valid_subsequence;
    for (int i = 0; i < strings.size(); i++){
        current = strings[i];

        // find repeated elements in a string
        bool repeat_flag = false;
        sort(current.begin(), current.end());
        for (int k = 0; k < current.size(); k++){
            if (current[k] == current[k+1]){
                repeat_flag = true;
                break;
                }
            }
            if (!repeat_flag){
                int j;
                vector<int> subsequence {i};
                valid_subsequence.push_back(subsequence);
                std::cout<<"Valid subsequence:"<< i << std::endl;
                bool flag;
                for (auto index : subsequence){
                    for (j = i+1; j < strings.size(); j++){
                        flag = true;
                        current = strings[index];
                        std::size_t found = current.find_first_of(strings[j]);
                        if (found == std::string::npos){
                            subsequence.push_back(j);
                        }
                    }
                    std::cout << " Valid subsequence:";
                    int length = 0;
                    for (auto entry: subsequence){
                        std::cout <<entry<<",";
                        length += strings[entry].size();
                        if (length > max_subseq_length)
                            max_subseq_length = length;
                    }
                    std::cout<<std::endl;
                    valid_subsequence.push_back(subsequence);
                }
            }
    }
            std::cout<<" Max sub seq length:" << max_subseq_length << std::endl;
}

