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

    //create instance of the class to access its members
    Student jamesB;

    //I still need to create these variables in main
    string line; // for the stringstream object
    string name;
    int studentID;
    string phone;
    double gpa;

    vector<string> fields;
    stringstream ss(line);
    string field;

    ifstream studentTxt("student.txt", ios::in);

    //catch file opening error
    if(!studentTxt){
        cerr << "File could not be opened"<< endl;
        return 1;
    } 

    while(getline(studentTxt, line)){
        vector<string> fields;
        stringstream ss(line);
        string field;

        while(getline(ss, field, ',')){
            fields.push_back(field);
        }

        //print each line with a for loop
        for(const string& f:fields){
            cout << f << "\n";
        }

        cout << endl;
    }

    //loop over the file and output the contents of each record
    //while(studentTxt >> name >> studentID >> phone >> gpa){
    //    jamesB.outLine(name, studentID, phone, gpa);
    //}
    //close the file
    studentTxt.close();

    return 0;
}
