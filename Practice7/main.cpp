#include <iostream>
#include <list>

using namespace std;

class Student {
public:
    string Name;
    int* Grades;
    int GradesCount;

    Student(string name, int gradesCount) : Name(name), GradesCount(gradesCount) {
        Grades = new int[GradesCount];
        for (int i = 0; i < GradesCount; i++) {
            Grades[i] = 0; // Ініціалізація всіх оцінок нулями
        }
    }

    // ??? destructor
//    ~Student(){
//        delete[] Grades;
//    }
};

list<Student> students;

Student* find_student(const string& studentName) {
    for (Student& student : students) {
        if (student.Name == studentName) {
            return &student;
        }
    }
    return nullptr;
}

void register_student() {
    cout << "Enter student name: ";
    string studentName;
    cin >> studentName;

    if (find_student(studentName) != nullptr) {
        cout << "This student already exists!" << endl;
        return;
    }

    int gradesCount;
    cout << "Enter number of grades: ";
    cin >> gradesCount;

    Student newStudent(studentName, gradesCount);
    students.push_back(newStudent);
    cout << "Student registered successfully!" << endl;
}

void remove_student() {
    cout << "Enter student name: ";
    string studentName;
    cin >> studentName;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->Name == studentName) {
            students.erase(it);
            cout << "Student removed successfully!" << endl;
            return;
        }
    }
    cout << "This student doesn't exist!" << endl;
}

void add_grade() {
    cout << "Enter student name: ";
    string studentName;
    cin >> studentName;

    Student* student = find_student(studentName);
    if (student == nullptr) {
        cout << "Student not found!" << endl;
        return;
    }

    cout << "Enter grade index (0 to " << student->GradesCount - 1 << "): ";
    int index;
    cin >> index;

    if (index < 0 || index >= student->GradesCount) {
        cout << "Invalid index!" << endl;
        return;
    }

    cout << "Enter grade: ";
    int grade;
    cin >> grade;
    student->Grades[index] = grade;
    cout << "Grade added successfully!" << endl;
}

void show_all_students() {
    for (const Student& student : students) {
        cout << "=====================\n";
        cout << "Student name: " << student.Name << endl;
        cout << "Grades: ";
        for (int i = 0; i < student.GradesCount; i++) {
            cout << student.Grades[i] << " ";
        }
        cout << "\n=====================\n";
    }
}

void calculate_average() {
    cout << "Enter student name: ";
    string studentName;
    cin >> studentName;

    Student* student = find_student(studentName);
    if (student == nullptr) {
        cout << "Student not found!" << endl;
        return;
    }

    int sum = 0;
    for (int i = 0; i < student->GradesCount; i++) {
        sum += student->Grades[i];
    }

    double average = static_cast<double>(sum) / student->GradesCount;
    cout << "Average grade for " << student->Name << " is: " << average << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n1 - Register student\n2 - Remove student\n3 - Add a grade\n4 - Show all students\n5 - Calculate average grade\n6 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                register_student();
                break;
            case 2:
                remove_student();
                break;
            case 3:
                add_grade();
                break;
            case 4:
                show_all_students();
                break;
            case 5:
                calculate_average();
                break;
            case 6:
                return 0;
            default:
                cout << "Wrong number, try again." << endl;
                break;
        }
    }
}
