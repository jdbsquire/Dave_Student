#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
    private:
        string name;
        string studentID;
        string phone;
        double gpa;

        static double highestGPA;//class variable

    public:
        Student();
        Student(const string& name, const string& id, const string& phone, double gpa);

        // Getters
        string getName() const;
        string getStudentID() const;
        string getPhone() const;
        double getGPA() const;

        // Setters
        void setName(const string& n);
        void setStudentID(const string& id);
        void setPhone(const string& p);
        void setGPA(double g);

        //Methods
        static double getHighestGPA();
        void outLine(const string&, int, const string&, double);
};

#endif
