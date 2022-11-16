#include <random>
#include <iostream>
#include <random>
#include <sstream>
#include <cstdlib>

using namespace std;

int main () {
  std::random_device rd;
  std::uniform_int_distribution<int> distribution(0, 99);
  int random_number = distribution(rd);
  string input;
  int input_number;
  while (true){
    cout << " Guess the number:" << endl;
    cin >> input_number;
    if (cin.fail()){

        cout << "The number is " << random_number << endl << 
        "Error encountered, exiting" << endl;
        return EXIT_FAILURE;
    }

    if (input_number < 0 || input_number > 99){
        cerr << "[WARNING]: Number must be between 0 and 99" << endl;
        continue;
    }

    if (input_number > random_number) cout << " Input number is greater \n";
    else if (input_number < random_number) cout << "Input number is smaller \n";
    else { 
        cout << " You have won \n. The number is " << random_number << endl;
        break;
    }

  }
  return EXIT_SUCCESS;
  
}
