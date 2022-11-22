#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <boost/lexical_cast.hpp>

int main(int argc, char *argv[]){
  if (argc != 3){
   std::cout << " Usage : ./task_2 " << "\"<INT>.<EXT>\"" <<  "\"<INT>.<EXT>\""
   << std::endl;
   return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i ++)
    std::cout << " Arguments are : " << argv[i] << std::endl;
  std::vector<std::string> filenames;
  int integers[2];
  std::vector<std::string> extensions {"",""};
  std::string s = argv[1];
  /*
  std::string::size_type j = s.find(".", 0);
  std::cout << " Index of string: " << j << " - substring: " << s.substr(0, j)
  << std::endl;
  integers[0] = stoi(s.substr(0, j));
  std::cout << " value of integer: " << integers[0] << std::endl;
  extensions.push_back(s.substr(j+1, s.length()-1));

  std::cout << " Filename : " << argv[1] << ", Integer: " << integers[0] <<
  ", extension" << extensions[0] << std::endl;
  */

  for (int i = 1; i < argc ; i ++ ){
    std::stringstream ss;
    ss << argv[i];
    std::string extension;
    ss >> integers[i - 1] >> extension;
    extensions[i-1] = extension;
  }
  for (auto ext : extensions)
    std::cout << " extensions are : " << ext << std::endl;
  double result;
  if ((extensions[0] == ".txt") && (extensions[1] == ".txt"))
    result = (integers[0]  + integers[1])/2.0f;
  else if ((extensions[0] == ".png") && (extensions[1] == ".png"))
    result = integers[0] + integers[1];
  else if ((extensions[0] == ".txt" ) && (extensions[1] == ".png"))
    result = integers[0] % integers[1];
  else {
    std::cerr << " Error : No conditions are met for prcessing the output" << std::endl;
    return EXIT_FAILURE;
    }

  std::cout << "Result is " << result << ".\n"; 

  return EXIT_SUCCESS;
}
