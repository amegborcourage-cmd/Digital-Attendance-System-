b#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string indexNumber;
    std::string name;
    Student(std::string idx, std::string n) : indexNumber(idx), name(n) {}
    void display() {
        std::cout << "Index: " << indexNumber << ", Name: " << name << "\n";
    }
};

std::vector<Student> students;

void addStudent() {
    std::string idx, name;
    std::cout << "Enter Index Number: ";
    std::cin >> idx;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    students.emplace_back(idx, name);
}

void viewStudents() {
    for (auto& s : students) s.display();
}

int main() {
    int choice;
    do {
        std::cout << "1. Add Student\n2. View Students\n3. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
        }
    } while (choice != 3);
    return 0;
}
void addStudent() {
    std::string idx, name;
    std::cout << "Enter Index Number: ";
    std::cin >> idx;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    if (idx.empty() || name.empty()) {
        std::cout << "Invalid input. Please try again.\n";
        return;
    }
    students.emplace_back(idx, name);
}
int main() {
    int choice;
    do {
        std::cout << "1. Add Student\n2. View Students\n3. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}
int main() {
    int choice;
    do {
        std::cout << "1. Add Student\n2. View Students\n3. Exit\n";
        std::cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
    return 0;
}
#include <vector>
#include <string>

using namespace std;

class AttendanceSession {
private:
    string courseName;
    string sessionDate;
    vector<string> presentStudents;

public:
    // Constructor
    AttendanceSession(string course, string date) {
        courseName = course;
        sessionDate = date;
    }

    // Mark attendance
    void markAttendance() {
        int number;
        string name;

        cout << "How many students are present? ";
        cin >> number;
        cin.ignore();

        for (int i = 0; i < number; i++) {
            cout << "Enter student " << i + 1 << " name: ";
            getline(cin, name);
            presentStudents.push_back(name);
        }

        cout << "Attendance recorded successfully!\n";
    }

    // Display session details
    void displaySession() const {
        cout << "\nCourse: " << courseName << endl;
        cout << "Date: " << sessionDate << endl;

        if (presentStudents.empty()) {
            cout << "No attendance recorded yet.\n";
        } else {
            cout << "Present Students:\n";
            for (int i = 0; i < presentStudents.size(); i++) {
                cout << i + 1 << ". " << presentStudents[i] << endl;
            }
        }
    }

    string getCourseName() const {
        return courseName;
    }
};

int main() {
    vector<AttendanceSession> sessions;
    int choice;

    do {
        cout << "\n====== ATTENDANCE SYSTEM ======\n";
        cout << "1. Create Lecture Session\n";
        cout << "2. Mark Attendance for a Session\n";
        cout << "3. View All Sessions\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

        case 1: {
            string course, date;
            cout << "Enter course name: ";
            getline(cin, course);
            cout << "Enter session date: ";
            getline(cin, date);

            sessions.push_back(AttendanceSession(course, date));
            cout << "Session created successfully!\n";
            break;
        }

        case 2: {
            if (sessions.empty()) {
                cout << "No sessions available.\n";
                break;
            }

            cout << "\nAvailable Sessions:\n";
            for (int i = 0; i < sessions.size(); i++) {
                cout << i + 1 << ". " << sessions[i].getCourseName() << endl;
            }

            int index;
            cout << "Select session number: ";
            cin >> index;
            cin.ignore();

            if (index > 0 && index <= sessions.size()) {
                sessions[index - 1].markAttendance();
            } else {
                cout << "Invalid selection.\n";
            }
            break;
        }

        case 3: {
            if (sessions.empty()) {
                cout << "No sessions created yet.\n";
            } else {
                for (int i = 0; i < sessions.size(); i++) {
                    cout << "\nSession " << i + 1 << ":";
                    sessions[i].displaySession();
                }
            }
            break;
        }

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
    int id;
    string name;
    int presentDays = 0;
    int absentDays = 0;
};

void markAttendance(vector<Student>& students) {
    char choice;

    cout << "\n--- Mark Attendance ---\n";
    for (auto &student : students) {
        while (true) {
            cout << "Is " << student.name << " present? (P/A): ";
            cin >> choice;

            if (choice == 'P' || choice == 'p') {
                student.presentDays++;
                break;
            }
            else if (choice == 'A' || choice == 'a') {
                student.absentDays++;
                break;
            }
            else {
                cout << "Invalid input! Enter P or A only.\n";
            }
        }
    }
}

void generateReport(const vector<Student>& students) {
    cout << "\n--- Attendance Report ---\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Present"
         << setw(10) << "Absent"
         << setw(15) << "Percentage\n";

    for (const auto &student : students) {
        int total = student.presentDays + student.absentDays;
        double percentage = (total > 0) ? 
            (double(student.presentDays) / total) * 100 : 0;

        cout << left << setw(10) << student.id
             << setw(20) << student.name
             << setw(10) << student.presentDays
             << setw(10) << student.absentDays
             << setw(14) << fixed << setprecision(2) << percentage << "%\n";
    }
}

int main() {
    int numberOfStudents;

    cout << "Enter number of students: ";
    while (!(cin >> numberOfStudents) || numberOfStudents <= 0) {
        cout << "Invalid number! Enter a positive number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    vector<Student> students(numberOfStudents);

    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin >> students[i].name;
    }

    int option;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Mark Attendance\n";
        cout << "2. Generate Report\n";
        cout << "3. Exit\n";
        cout << "Choose option: ";
        cin >> option;

        switch (option) {
            case 1:
                markAttendance(students);
                break;
            case 2:
                generateReport(students);
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid option!\n";
        }

    } while (option != 3);

    return 0;
}
