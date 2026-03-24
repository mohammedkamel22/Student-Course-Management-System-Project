# Student Management System

A console-based C++ application for managing student records, including adding, removing, searching, sorting students by GPA, and enrolling them in courses.

## Description

This project is a simple **Student Management System** built using core C++ concepts such as:

- **OOP (Object-Oriented Programming):** Classes, Inheritance, Encapsulation.
- **STL Containers:** `vector` for storing students, `set` for storing unique courses per student.
- **STL Algorithms:** `sort` with a custom comparator for ranking students by GPA.

The system provides an interactive menu-driven interface that allows users to perform various operations on student data.

## Features

- Add a new student with a unique ID, name, and GPA (0.0 – 4.0).
- Remove a student by ID.
- Search for a student by ID.
- Display all registered students.
- Enroll a student in a course (duplicates are automatically prevented).
- View all courses for a specific student.
- Sort and display students by GPA in descending order.
- Input validation for unique IDs and valid GPA range.

## UML Class Diagram

```
+---------------------------+
|          Person           |
+---------------------------+
| # name : string           |
+---------------------------+
|                           |
+---------------------------+
              ▲
              |  (Inheritance)
              |
+---------------------------+
|          Student          |
+---------------------------+
| - id      : int           |
| - gpa     : double        |
| - courses : set<string>   |
+---------------------------+
| + Student(int, string,    |
|           double)         |
| + displayInfo() : void    |
| + getId() : int           |
| + get_gpa() : double      |
| + enrollCourse(string)    |
|                  : void   |
| + printMyCourses() : void |
+---------------------------+
```

## Prerequisites

- A C++ compiler that supports **C++11** or later (e.g., `g++`, `clang++`, MSVC).

## Installation & Compilation

1. Clone or download the repository:
   ```bash
   git clone https://github.com/your-username/student-management-system.git
   cd student-management-system
   ```

2. Compile the source code:
   ```bash
   g++ -o student_system main.cpp -std=c++11
   ```

3. Run the program:
   ```bash
   ./student_system
   ```

## Usage

After running the program, you will see an interactive menu:

```
--- Student Management System ---
1. Add Student
2. Remove Student
3. Search Student
4. Display All Students
5. Enroll Student in Course
6. Show Student Courses
7. Sort Students by GPA
8. Exit
Enter your choice:
```

### Example

```
Enter your choice: 1
Enter Student ID: 101
Enter Name: Ahmed Ali
Enter GPA (0.0 to 4.0): 3.5
Student added successfully.

Enter your choice: 5
Enter Student ID to enroll in a course: 101
Enter Course Name: Mathematics
Course added successfully.

Enter your choice: 6
Enter Student ID to show courses: 101
Courses for student: Ahmed Ali
- Mathematics
-------------------
```

## Project Structure

```
student-management-system/
├── main.cpp        # Source code
└── README.md       # Project documentation
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
