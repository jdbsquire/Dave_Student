#include "Student.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

int main() {
    /************************INPUT*********************/
    /*************************FILE*********************/
    //string to receive the filename entered by the user
    //What material do I need to get this program going?
    //A string to receive the fileName student.txt
    string fileName;
    //prompt the user for the name of the file where the data is stored
    cout << "What is the name of the file with the student data?\n"
         << "The fileName in this program is student.txt ";
    //wait for the user to enter the name of the file
    cin >> fileName;
    //use the infile stream to name the stream with the fileName as the argument
    ifstream infile(fileName);
    //error check to see if the file is open using a cerr statement
    if (!infile) {
        cerr << "Error opening " << fileName << endl;
        return 1;
    }

    /*********PREPARE THE DATA FOR PROCESSING**********/
    /**********************LINE************************/
    //create a vector called students that will hold Student objects!
    vector<Student> students;
    //create a string to receive each line of the file and parse it
    string line;

    /*****LOOP THROUGH THE inFile and parse each line**/
    /*USING getline AUTOMATICALLY PARSES LINE BY LINE**/
    /*I KNOW WHAT THE DATA LOOKS LIKE BECAUSE I LOOKED AT IT FIRST*/
    while (getline(infile, line)){
        /*WHEN I HIT AN EMPTY LINE, THE PROGRAM CONTINUES*/
        if(line.empty()) continue;
        /*CREATE A stringstream OBJECT CALLED ss TO STREAM EACH ELEMENT OF THE DATA
          INTO THEIR RESPECTIVE VARIABLES*/
        // line is the argument
        stringstream ss(line);
        /*CREATE THE NECESSARY VARIABLES*/
        /*These are also the variables expected by the Student constructor*/
        string name, id, phone;
        double gpa;

        /*PARSE EACH ELEMENT INTO ITS RESPECTIVE VARIABLE USING GETLINE*/
        /* the comma is the delimiter*/
        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, phone, ',');
        ss >> gpa;

        /*PUSH THE RECORD ONTO THE BACK OF THE VECTOR students CREATED ON LINE 42*/
        /*Student is the object copied onto the back of the vector*/
        /*I know the params of Student constructor because I looked at the .cpp file*/
        students.push_back(Student(name, id, phone, gpa));
        /* The students vector is now populated and ready for more manipulation*/

    }

    /*After initial processing the data,
           close the file always */
    infile.close();

    /* NOW I CAN SORT, VIEW, AND MANIPULATE THE DATA IN THE WAY I WANT TO*/

    /*Create a variable to get the highest gpa*/
    /*This was tracked each time the constructor was called
      and 'saved' in the static/global class variable called highestGPA*/
    /* I know the type because I looked at the .cpp file */
    /* Note how to call this class variable!*/
    double highest = Student::getHighestGPA();
    //Show the user the highest GPA
    cout << "Highest GPA found: " << highest << "\n\n";

    /*  SHOW THE DIFFERENCE BETWEEN highest gpa and each student gpa  */
    // demonstration of the auto& statement that leaves the program to understand the proper type
    
    // for (const auto& s : students) {
    
    // traditional for loop through the student objects to find each student's difference between
    // their grade and the highest gpa
    for(const Student & s : students) {
        cout << s.getName()
             << " (ID: " << s.getStudentID() << ") "
             //calculate the difference between highest gpa and the student's grade
             << "is " << highest - s.getGPA()
             << " points below the highest GPA.\n";
    }

    cout << "****************SORTING DATA BLOCK************************\n";
    /* SORTING THE DATA BY GPA descending*/
    sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return a.getGPA() > b.getGPA();//descending
        });

}