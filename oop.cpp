#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;
public:
    User(string n) : name(n) {}
    virtual void menu() = 0;
    string getName() { return name; }
};

class Admin : public User {
public:
    Admin(string n) : User(n) {}
    void menu() {
        cout << "Admin Menu:\n1. Create Course\n2. View Users\n";
    }
};

class Instructor : public User {
public:
    Instructor(string n) : User(n) {}
    void menu() {
        cout << "Instructor Menu:\n1. Post Assignment\n2. Grade Submission\n";
    }
};

class Student : public User {
public:
    Student(string n) : User(n) {}
    void menu() {
        cout << "Student Menu:\n1. View Courses\n2. Submit Assignment\n";
    }
};

class Course {
private:
    string courseID;
    string courseName;
    string teacher;
    int creditHours;
    int fees;
    int registeredStudents;
    static const int maxStudents = 50;

public:
    Course() : courseID(""), courseName(""), teacher(""), creditHours(0), fees(0), registeredStudents(0) {}
    Course(string id, string name, string t, int credit=3, int fee=5000) 
        : courseID(id), courseName(name), teacher(t), creditHours(credit), fees(fee), registeredStudents(0) {}

    void show() {
        cout << "Course ID: " << courseID
             << " | Name: " << courseName
             << " | Teacher: " << teacher
             << " | Registered Students: " << registeredStudents
             << "/" << maxStudents << endl;
    }

    void registerStudent() {
        if (registeredStudents < maxStudents) registeredStudents++;
        else cout << "Course full!\n";
    }
};

class Assignment {
public:
    string title;
    string studentSubmission;
    Assignment() {}
    Assignment(string t) { title = t; }
    void submit(string s) { studentSubmission = s; }
};

int main() {
    Admin admin("Sir Admin");
    Instructor instructor("Maam Saima Javed");
    Student student("Khaleel Ahmed");

    Course oop("CS102", "OOP with C++", "Maam Saima Javed", 3, 6000);
    Assignment a1("Assignment 1");

    cout << "\nSimple Bahria LMS \n\n";

    admin.menu();
    cout << "\n";
    instructor.menu();
    cout << "\n";
    student.menu();
    cout << "\n";

    cout << "Created Course:\n";
    oop.show();

    cout << "\nRegistering Students...\n";
    for (int i = 0; i < 52; i++) oop.registerStudent();
    oop.show();

    cout << "\nStudent submits assignment...\n";
    a1.submit("My solution file");
    cout << "Submission saved.\n";

    return 0;
}
