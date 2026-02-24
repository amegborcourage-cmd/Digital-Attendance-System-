#include <iostream>
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
