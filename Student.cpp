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

double Student::highestGPA = 0.0;//setting variable to 0.0

using namespace std;

Student::Student():name(""), studentID(""), phone(""), gpa(0.0) {}//constructor set to null or 0

Student::Student(const string& n, const string& id, const string & p, double g)//overridding the above method with constants
                 : name(n), studentID(id), phone(p), gpa(g)//byref saves memory
    {
        if(g > highestGPA)
            highestGPA = g;
    }

string Student::getName() const{//casnnot change instanc4e variable for the class
    return name;
}

string Student::getStudentID() const{//alway7s constant in industry
    return studentID;
}

string Student::getPhone() const{
    return phone;
}

double Student::getGPA() const{
    return gpa;
}

void Student::setName(const string &n){
    name = n;
}

void Student::setStudentID(const string &id){
    studentID = id;
}

void Student::setPhone(const string& p){
    phone = p;
}

void Student::setGPA(double g){
    gpa = g;
    if (g > highestGPA)
        highestGPA = g;
}

double Student::getHighestGPA() { 
    return highestGPA; 
}

void Student::outLine(const string& name, int studentID, 
            const string& phone, double gpa){
                cout 
                    << name << " " << studentID << " "
                    << phone << " " << gpa << "\n";
            }