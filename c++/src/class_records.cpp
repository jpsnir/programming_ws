// Class records and stats
// Created by Jagatpreet Singh Nir on 5/11/20.
// NUID: 001406635
// Special compile instructions:

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int number_of_students; // class size
float average_grade; // average of class
int *grades;
string *lastnames;
int topper_id;


// Function declaration statements
void readNumber(int& inputNumber);
void readString(string& input);
float computeAverage(int array[],int& N);

int main(int argc,char** argv)
{
    int inputNumber = 0;

    // Ask until user enters a valid entry as number of students
    while(inputNumber<=0){ // Number of students cannot be negative or zero
        // for a real class.
        cout << "Please enter number of students (valid entries are positive numbers): ";
        readNumber(inputNumber);
    }
    number_of_students = inputNumber;
    cout<<"Number of students:"<<number_of_students<<endl;

    // Dynamic allocation to the variables
    grades = new int[number_of_students];
    lastnames = new string[number_of_students];
    int max_grade = 0; // temporary variable to store max grade
    for(int i = 0; i<number_of_students;i++)
    {
        cout<<"Enter last name of student "<<i+1<<" :";
        readString(lastnames[i]);

        inputNumber = -1;
        while (inputNumber >100 || inputNumber<0)
        {
            cout<<"Enter grade of student "<<i+1<<" :";
            readNumber(inputNumber);
        }
        grades[i] = inputNumber;

        // Store the max_grade
        if (grades[i]>max_grade)
        {
            topper_id = i;
            max_grade = grades[i];
        }
    }
    // Print all the data of students
    for (int i =0; i<number_of_students;i++)
    {
        cout<<lastnames[i]<<" has marks = "<<grades[i]<<endl;
    }

    // Print the results: average marks, topper of the class, and the students < 50
    cout<<"The average marks are : "<<computeAverage(grades,number_of_students)<<endl;
    cout<<"The topper of the class is student with name "
        <<lastnames[topper_id]<<" with marks:"<<grades[topper_id]<<endl;

    // Output list of students with grades less than 50
    for (int i = 0; i<number_of_students;i++)
        if(grades[i]<50)
            cout<<"Student with name "<<lastnames[i]<<" has marks :"<<grades[i]<<endl;
    return(0);
}

float computeAverage(int array[],int& N)
{
    float sum = 0; // stores the sum of grades
    for(int i = 0; i<N;i++)
        sum += array[i];
    return sum/N; //compute and return the average
}

void readNumber(int& inputNumber)
/*
 * Implements a function which only reads an integer(positive or negative) from
 * user, otherwise prompts the user again
 */
{
    string inputString;
    while (true) {
        getline(cin, inputString);

        // This code converts from string to number safely.
        stringstream myStream(inputString);
        if (myStream >> inputNumber)
            break;
        cout << "Invalid entry. You entered a character" << endl<<endl;
        cout << "Enter again:";
    }
    cout << "You entered: " << inputNumber << endl << endl;
}

void readString(string& input)
{
    getline(cin,input);
}
