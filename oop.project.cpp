#include "oop.project.p"

int main() {
    LMS system;
    int mainChoice = 0;

    while (true) {
        cout << "\n====== LOGIN SYSTEM ======" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Teacher Login" << endl;
        cout << "3. Student Login" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> mainChoice;
        cin.ignore();

        if (mainChoice == 1) {
            string id, pass;
            cout << "Admin ID: "; getline(cin, id);
            cout << "Password: "; getline(cin, pass);

            if (system.loginAdmin(id, pass) != -1) {
                int c = 0;
                while (c != 6) {
                    cout << "\n--- ADMIN PANEL ---" << endl;
                    cout << "1. Add Student" << endl;
                    cout << "2. Add Teacher" << endl;
                    cout << "3. Add Admin" << endl;
                    cout << "4. Add Course" << endl;
                    cout << "5. Enroll Student" << endl;
                    cout << "6. Logout" << endl;
                    cout << "Choice: ";
                    cin >> c;
                    cin.ignore();
                    if (c == 1) system.addStudent();
                    else if (c == 2) system.addTeacher();
                    else if (c == 3) system.addAdmin();
                    else if (c == 4) system.addCourse();
                    else if (c == 5) system.enrollStudent();
                }
            }
        }

        else if (mainChoice == 2) {
            string id, pass;
            cout << "Teacher ID: "; getline(cin, id);
            cout << "Password: "; getline(cin, pass);

            if (system.loginTeacher(id, pass) != -1) {
                int c = 0;
                while (c != 4) {
                    cout << "\n--- TEACHER PANEL ---" << endl;
                    cout << "1. Add Assignment" << endl;
                    cout << "2. Grade Assignment" << endl;
                    cout << "3. View Submissions" << endl;
                    cout << "4. Logout" << endl;
                    cout << "Choice: ";
                    cin >> c;
                    cin.ignore();
                    if (c == 1) system.addAssignment();
                    else if (c == 2) system.gradeSubmission();
                    else if (c == 3) system.showSubmissions();
                }
            }
        }

        else if (mainChoice == 3) {
            string id, pass;
            cout << "Student ID: "; getline(cin, id);
            cout << "Password: "; getline(cin, pass);

            if (system.loginStudent(id, pass) != -1) {
                int c = 0;
                while (c != 3) {
                    cout << "\n--- STUDENT PANEL ---" << endl;
                    cout << "1. Submit Assignment" << endl;
                    cout << "2. View Submissions" << endl;
                    cout << "3. Logout" << endl;
                    cout << "Choice: ";
                    cin >> c;
                    cin.ignore();
                    if (c == 1) system.submitAssignment();
                    else if (c == 2) system.showSubmissions();
                }
            }
        }

        else if (mainChoice == 4) {
            system.saveAll();
            break;
        }
    }

    return 0;
}
