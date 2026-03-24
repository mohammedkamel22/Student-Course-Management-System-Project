#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Person {
protected:
    string name;
};

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;

public:
    Student(int studentId, string studentName, double studentGpa) {
        id = studentId;
        name = studentName;
        gpa = studentGpa;
    }

    void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "GPA: " << gpa << endl;
        cout << "-------------------" << endl;
    }

    int getId() {
        return id;
    }

    double get_gpa() {
        return gpa;
    }

    void enrollCourse(string courseName) {
        courses.insert(courseName); 
    }

    void printMyCourses() {
        cout << "Courses for student: " << name << endl;
        if (courses.empty()) {
            cout << "No courses enrolled yet." << endl;
            return;
        }
       for (int i = 0; i < courses.size(); i++) {
            cout << "- " << courses[i] << endl;
        }
        cout << "-------------------" << endl;
    }
};

vector<Student> studentList;

bool compareStudents(Student student1, Student student2) {
    return student1.get_gpa() > student2.get_gpa();
}

void searchStudent(int id_num) {
    bool found = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getId() == id_num) {
            studentList[i].displayInfo();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!" << endl;
    }
}

void removeStudent(int id_num) {
    bool found = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getId() == id_num) {
            studentList.erase(studentList.begin() + i);
            cout << "Student removed successfully." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!" << endl;
    }
}

void displayStudentCourses(int id_num) {
    bool found = false;
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getId() == id_num) {
            studentList[i].printMyCourses();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!" << endl;
    }
}

bool isIdUnique(int id_num) {
    for (int i = 0; i < studentList.size(); i++) {
        if (studentList[i].getId() == id_num) {
            return false;
        }
    }
    return true;
}

int main() {
    int choice;
    int idInput;
    string nameInput, courseInput;
    double gpaInput;

    do {
        cout << "\n--- Student Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Enroll Student in Course" << endl;
        cout << "6. Show Student Courses" << endl;
        cout << "7. Sort Students by GPA" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter Student ID: ";
                cin >> idInput;
                
                if (!isIdUnique(idInput)) {
                    cout << "Error: ID already exists. Each student must have a unique ID.\n";
                    break;
                }

                cin.ignore(); 

                cout << "Enter Name: ";
                getline(cin, nameInput);

                cout << "Enter GPA (0.0 to 4.0): ";
                cin >> gpaInput;
                
                if (gpaInput < 0.0 || gpaInput > 4.0) {
                    cout << "Error: GPA must be between 0.0 and 4.0.\n";
                    break;
                }

                studentList.push_back(Student(idInput, nameInput, gpaInput));
                cout << "Student added successfully.\n";
                break;
            }
            case 2:
                cout << "Enter Student ID to remove: ";
                cin >> idInput;
                removeStudent(idInput);
                break;
            case 3:
                cout << "Enter Student ID to search: ";
                cin >> idInput;
                searchStudent(idInput);
                break;
            case 4:
                if (studentList.empty()) {
                    cout << "No students in the system yet.\n";
                } else {
                    cout << "\n--- All Students ---\n";
                    for (int i = 0; i < studentList.size(); i++) {
                        studentList[i].displayInfo();
                    }
                }
                break;
            case 5: {
                cout << "Enter Student ID to enroll in a course: ";
                cin >> idInput;
                
                bool found = false;
                for (int i = 0; i < studentList.size(); i++) {
                    if (studentList[i].getId() == idInput) {
                        cout << "Enter Course Name: ";
                        cin >> courseInput; 
                        studentList[i].enrollCourse(courseInput);
                        cout << "Course added successfully.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student not found!\n";
                }
                break;
            }
            case 6:
                cout << "Enter Student ID to show courses: ";
                cin >> idInput;
                displayStudentCourses(idInput);
                break;
            case 7:
                if (studentList.empty()) {
                    cout << "No students to sort.\n";
                } else {
                    sort(studentList.begin(), studentList.end(), compareStudents);
                    cout << "Students sorted by GPA successfully!\n";
                }
                break;
            case 8:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}