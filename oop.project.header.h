#ifndef LMS_H
#define LMS_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string password;

public:
    Person() {
        name = "";
        id = "";
        password = "";
    }

    void setName(string n) { name = n; }
    void setID(string i) { id = i; }
    void setPassword(string p) { password = p; }

    string getName() { return name; }
    string getID() { return id; }
    string getPassword() { return password; }

    void inputBasic() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        getline(cin, id);
        cout << "Enter Password: ";
        getline(cin, password);
    }

    void displayBasic() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Student : public Person {
public:
    Student() : Person() {}
    void display() { cout << " STUDENT DETAILS " << endl; displayBasic(); }
    void studentMenuTitle() { cout << "\n STUDENT MENU " << endl; }
};

class Teacher : public Person {
public:
    Teacher() : Person() {}
    void display() { cout << "--- TEACHER DETAILS ---" << endl; displayBasic(); }
    void teacherMenuTitle() { cout << "\n====== TEACHER MENU ======" << endl; }
};

class Admin : public Person {
public:
    Admin() : Person() {}
    void display() { cout << "--- ADMIN DETAILS ---" << endl; displayBasic(); }
    void adminMenuTitle() { cout << "\n====== ADMIN MENU ======" << endl; }
};

class Course {
public:
    string code;
    string title;
    string students[100];
    int studentCount;
    string assignments[100];
    int assignmentCount;

    Course() { code = ""; title = ""; studentCount = 0; assignmentCount = 0; }

    void inputCourse() {
        cout << "Enter Course Code: "; getline(cin, code);
        cout << "Enter Course Title: "; getline(cin, title);
    }

    void displayCourse() { cout << "Course Code: " << code << endl << "Course Title: " << title << endl; }
    void addStudent(string sid) { students[studentCount++] = sid; }
    void addAssignment(string a) { assignments[assignmentCount++] = a; }
    void showStudents() { for (int i = 0; i < studentCount; i++) cout << i + 1 << ". " << students[i] << endl; }
    void showAssignments() { for (int i = 0; i < assignmentCount; i++) cout << i + 1 << ". " << assignments[i] << endl; }
};

class Submission {
public:
    string studentID;
    string courseCode;
    string assignmentName;
    string fileName;
    string grade;

    Submission() { studentID = ""; courseCode = ""; assignmentName = ""; fileName = ""; grade = "Not Graded"; }

    void inputSubmission() {
        cout << "Enter Student ID: "; getline(cin, studentID);
        cout << "Enter Course Code: "; getline(cin, courseCode);
        cout << "Enter Assignment Name: "; getline(cin, assignmentName);
        cout << "Enter File Name: "; getline(cin, fileName);
    }

    void displaySubmission() {
        cout << "Student ID: " << studentID << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Assignment: " << assignmentName << endl;
        cout << "File: " << fileName << endl;
        cout << "Grade: " << grade << endl;
        cout << "------------------------" << endl;
    }
};

class LMS {
public:
    Student students[100];
    Teacher teachers[50];
    Admin admins[10];
    Course courses[50];
    Submission submissions[300];
    int studentCount, teacherCount, adminCount, courseCount, submissionCount;

    LMS() { studentCount = teacherCount = adminCount = courseCount = submissionCount = 0; }

    void addStudent() { students[studentCount++].inputBasic(); }
    void addTeacher() { teachers[teacherCount++].inputBasic(); }
    void addAdmin() { admins[adminCount++].inputBasic(); }
    void addCourse() { courses[courseCount++].inputCourse(); }

    void enrollStudent() {
        string sid, cc;
        cout << "Enter Student ID: "; getline(cin, sid);
        cout << "Enter Course Code: "; getline(cin, cc);
        for (int i = 0; i < courseCount; i++) if (courses[i].code == cc) courses[i].addStudent(sid);
    }

    int loginStudent(string id, string pass) {
        for (int i = 0; i < studentCount; i++) if (students[i].getID() == id && students[i].getPassword() == pass) return i;
        return -1;
    }
    int loginTeacher(string id, string pass) {
        for (int i = 0; i < teacherCount; i++) if (teachers[i].getID() == id && teachers[i].getPassword() == pass) return i;
        return -1;
    }
    int loginAdmin(string id, string pass) {
        for (int i = 0; i < adminCount; i++) if (admins[i].getID() == id && admins[i].getPassword() == pass) return i;
        return -1;
    }

    void addAssignment() {
        string cc, an;
        cout << "Enter Course Code: "; getline(cin, cc);
        cout << "Enter Assignment Name: "; getline(cin, an);
        for (int i = 0; i < courseCount; i++) if (courses[i].code == cc) courses[i].addAssignment(an);
    }

    void gradeSubmission() {
        string sid, cc, an, g;
        cout << "Student ID: "; getline(cin, sid);
        cout << "Course Code: "; getline(cin, cc);
        cout << "Assignment Name: "; getline(cin, an);
        cout << "Grade: "; getline(cin, g);
        for (int i = 0; i < submissionCount; i++)
            if (submissions[i].studentID == sid && submissions[i].courseCode == cc && submissions[i].assignmentName == an)
                submissions[i].grade = g;
    }

    void submitAssignment() { submissions[submissionCount++].inputSubmission(); }
    void showSubmissions() { for (int i = 0; i < submissionCount; i++) submissions[i].displaySubmission(); }
    void saveAll() { ofstream f("backup.txt"); f << "Backup Created" << endl; f.close(); }
};

#endif
