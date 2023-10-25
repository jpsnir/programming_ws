#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longest_common_prefix1(const vector<string>& s_list){
    // Solution1: 
    /*
    1. choose two strings [i] and [i+1]; Assume substring = string[i],
        and comparison string = string[i+1]
    2. find subtring that is common:
        2.1 for each substring in string[i] (0, j), compare with the same in
        in string[i+1]
        2.2 if True, assign common string substring
    3. update substring = common_string, comparison_string = string [i+2], repeat 2
    
    EDGE CASES:
    1. If the substring at any point is an empty string, stop the loop
    */
    string substring = s_list[0];
    string comparison_string = "";
    for (int i = 0; i < s_list.size(); i++){
        string common_string = "";
        comparison_string = s_list[i];
        int min_num = (comparison_string.size() <=
        substring.size()) ? comparison_string.size() : substring.size();
        for (int j = 0 ; j <= min_num ; j++){
            if (substring.substr(0, j) == comparison_string.substr(0, j))
                common_string = substring.substr(0, j);
        }
        substring = common_string;
        std::cout << " Substring: " << i << "-" << substring << std::endl;
    }
    std::cout << " final substring:" << substring << std::endl;
    return substring;
}

int main(int argc, char * argv[]){
    if (argc < 2)
        std::cout<< " Usage : ./longest_common_prefix <str1> <str2> ...<strn>" <<
        std::endl;
    vector<string> s_list;
    for (int i = 1; i < argc ; i++){
        s_list.push_back(*(argv + i));
        std::cout << *(argv+i) << std::endl;
    }
    std::cout << " Check if list is filled" << std::endl;
    for (auto s : s_list){
        std::cout << s << std::endl;
    }
    std::cout << " FUnction call" << std::endl;
    longest_common_prefix1(s_list);
}


