#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void string_split_string_using_stream(std::string input);
int main() {
    std::string input = "cam0_17197547_20230503_003300_1683163995554372";
    std::vector<std::string> tokens;
    size_t startPos = 0;
    size_t endPos = input.find("_");
    while (endPos != std::string::npos) {
        tokens.push_back(input.substr(startPos, endPos - startPos));
        startPos = endPos + 1;
        endPos = input.find('_', startPos);
    }

    tokens.push_back(input.substr(startPos));
    for (const auto& str:tokens) {
        std::cout << str << std::endl;
    }

    // approach using string stream
    string_split_string_using_stream(input);
    return 0;

}

void string_split_string_using_stream(std::string input){
    std::stringstream iss(input);
    std::vector<std::string> tokens;
    std::string token;
    while(std::getline(iss, token, '_')){
        tokens.push_back(token);
    }

    for (const auto& str:tokens){
        std::cout << str << std::endl;
    }

    double t = 0;
    if(!tokens.empty()){
        std::stringstream lastToken(tokens.back());
        lastToken >> t;
    }
    std::cout << " Time stamp is: " << t << std::endl;
}
