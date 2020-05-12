//
// Created by jagat on 5/11/20.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string input;
float average_grade;
typedef struct{
    string name;
    int grade;
}Student;
bool first = true;
Student topper;
Student *students;


int main(int argc,char** argv)
{
    int number_of_students = 0;

    while (true) {
        cout << "Please enter number of students (valid entries are positive numbers): ";
        getline(cin, input);

        // This code converts from string to number safely.
        stringstream myStream(input);
        if (myStream >> number_of_students)
            if(number_of_students>=0)
                break;
        cout << "Invalid entry for number of students (negative,zero, or other characters entered)" << endl;
    }
    cout << "You entered: " << number_of_students << endl << endl;

    //for (int i = 0; i < number_of_students; )
    cout<<"Number of students:"<<number_of_students<<endl;
    return(0);
}