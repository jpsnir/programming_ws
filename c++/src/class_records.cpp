//
// Created by jagat on 5/11/20.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int number_of_students;
float average_grade;
int *grades;
string *lastnames;
bool first = true;
string topper;
int top_grade;

void readNumber(int& inputNumber);
void readString(string& input);

int main(int argc,char** argv)
{
    int inputNumber = 0;

    // Ask until user enters a positive number of students
    while(inputNumber<=0){
        cout << "Please enter number of students (valid entries are positive numbers): ";
        readNumber(inputNumber);
    }
    number_of_students = inputNumber;
    cout<<"Number of students:"<<number_of_students<<endl;

    grades = new int[number_of_students];
    lastnames = new string[number_of_students];

    for(int i = 0; i<number_of_students;i++)
    {
        cout<<"Enter last name of student:";
        readString(lastnames[i]);
        cout<<"Enter grades of student";
        readNumber(grades[i]);
    }

    for (int i =0; i<number_of_students;i++)
    {
        cout<<lastnames[i]<<" has marks = "<<grades[i]<<endl;
    }
    return(0);
}

void readNumber(int& inputNumber)
{
    string inputString;
    while (true) {
        getline(cin, inputString);

        // This code converts from string to number safely.
        stringstream myStream(inputString);
        if (myStream >> inputNumber)
            break;
        cout << "Invalid entry" << endl<<endl;
        cout << "Enter again:";
    }
    cout << "You entered: " << inputNumber << endl << endl;
}

void readString(string& input)
{
    getline(cin,input);
}