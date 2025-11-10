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
    
    ifstream studentTxt("student.txt", ios::in);

    //catch file opening error
    if(!studentTxt){
        cerr << "File could not be opened"<< endl;
        exit(EXIT_FAILURE);
    }

    //I still need to create these variables in main
    string name;
    int studentID;
    string phone;
    double gpa;

    //loop over the file and output the contents of each record
    while(studentTxt >> name >> studentID >> phone >> gpa){
        cout << name << studentID << phone << gpa << endl;
    }

    return 0;
}
