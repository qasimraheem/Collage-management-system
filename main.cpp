#include <iostream>

using namespace std;

#include "Semester.h"
#include "Student.h"
#include "StudentList.h"
#include "Subject.h"
#include "StudentList.h"
#include "Teacher.h"
#include "TeacherList.h"
#include "SubjectList.h"
#include "string.h"

TeacherList teachers;
SubjectList subjects;
StudentList students;

using namespace std;

void menu();

int main();

void showTeacher() {
    teachers.print();
}

void addTeacher() {
    string name;
    string gender;
    float salary;
    long int number;
    string email;
    cout << "\nEnter Name:";
    cin >> name;
    cout << "\nEnter Email:";
    cin >> email;

    cout << "\nEnter Gender:";
    cin >> gender;

    cout << "\nEnter Salary:";
    cin >> salary;

    cout << "\nEnter Number:";
    cin >> number;

    Teacher teacher(name, gender, salary, number, email);
    teachers.insertAtTail(teacher);
}

void deleteTeacher() {
    string name;
    cout << "\nEnter Name of Teacher:";
    cin >> name;
    teachers.deleteNode(name);
}

void teacherMenu() {
    char opt = '.';
    cout << "1.Show Teacher" << endl;
    cout << "2.Add Teacher" << endl;
    cout << "3.Delete Teacher" << endl;
    cout << "0.Back" << endl;
    cin >> opt;
    switch (opt) {
        case '1': {
            showTeacher();
            break;
        }
        case '2': {
            addTeacher();
            break;
        }
        case '3': {
            deleteTeacher();
            break;
        }
        case '0': {
            menu();
        }
        default: {
            cout << "INVALID INPUT!!";
        }
    }
    teacherMenu();
}

void showSubject() {
    subjects.print();
};

void addSubject() {

    string name;
    int creditHours;
    float fees;
    Teacher teacher;
    cout << "\nEnter Name:";
    cin >> name;
    cout << "\nEnter CreditHours:";
    cin >> creditHours;
    cout << "\nEnter Fees:";
    cin >> fees;

    showTeacher();
    string teachername;
    cout << "\nSelect Teacher Name:";
    cin >> teachername;
    Teacher *temp = teachers.search(teachername);
    teacher = *temp;
    cout << "\nSelected Teacher is:" << endl;
    teacher.print();

    Subject subject(name, creditHours, fees, teacher);
    subjects.insertAtTail(subject);

}

void deleteSubject() {
    string name;
    cout << "\nEnter Name of Subject:";
    cin >> name;
    subjects.deleteNode(name);
}

void subjectMenu() {
    char opt = '.';
    cout << "1.Show Subject" << endl;
    cout << "2.Add Subject" << endl;
    cout << "3.Delete Subject" << endl;
    cout << "0.Back" << endl;
    cin >> opt;
    switch (opt) {
        case '1': {
            showSubject();
            break;
        }
        case '2': {
            addSubject();
            break;
        }
        case '3': {
            deleteSubject();
            break;
        }
        case '0': {
            menu();
        }
        default: {
            cout << "INVALID INPUT!!";
        }
    }
    subjectMenu();
}

void showStudent() {
    students.print();
}

void addStudent() {

    string name;
    int age;
    long int number;
    string email;
    string rollNumber;

    cout << "\nEnter Name:";
    cin >> name;
    cout << "\nEnter age:";
    cin >> age;
    cout << "\nEnter number:";
    cin >> number;
    cout << "\nEnter email:";
    cin >> email;
    cout << "\nEnter rollNumber:";
    cin >> rollNumber;

    Student student(name, age, number, email, rollNumber);
    students.insertAtTail(student);

}

void deleteStudent() {
    string rollnumber;
    cout << "\nEnter Roll Number of Student:";
    cin >> rollnumber;
    students.deleteNode(*students.search(rollnumber));
}

void studentMenu() {
    char opt = '.';
    cout << "1.Show Students" << endl;
    cout << "2.Add Student" << endl;
    cout << "3.Delete Student" << endl;
    cout << "0.Back" << endl;
    cin >> opt;
    switch (opt) {
        case '1': {
            showStudent();
            break;
        }
        case '2': {
            addStudent();
            break;
        }
        case '3': {
            deleteStudent();
            break;
        }
        case '0': {
            menu();
            break;
        }
        default: {
            cout << "INVALID INPUT!!";
        }
    }
    studentMenu();
}

void menu() {
    char opt = '.';
    cout << "1.Teachers Menu" << endl;
    cout << "2.Subject Menu" << endl;
    cout << "3.Student Menu" << endl;
    cout << "0.Back" << endl;
    cin >> opt;
    switch (opt) {
        case '1': {
            teacherMenu();
            break;
        }
        case '2': {
            subjectMenu();
            break;
        }
        case '3': {
            studentMenu();
            break;
        }
        case '0': {
            main();
            break;
        }
        default: {
            cout << "INVALID INPUT!!";
        }
    }

}

void StudentLogin(Student *student) {
    while (true) {


        char opt = '.';
        cout << "1.Show Data" << endl;
        cout << "2.Enroll Subject" << endl;
        cout << "3.Insert Marks" << endl;
        cout << "4.Calculate CGPA" << endl;
        cout << "5.Jump to Next Semester" << endl;
        cout << "0.Back" << endl;

        cin >> opt;
        switch (opt) {
            case '1': {
                student->print();
                for (int i = 0; i < student->getCurrentSemester(); i++) {
                    cout << "Semester " << i << endl;
                    student->getSemester()[i].print();
                }
                break;
            }
            case '2': {
                if (student->getCurrentSemester() == 0) {
                    student->setCurrentSemester(student->getCurrentSemester() + 1);
                }
                showSubject();
                string name;
                cout << "\nEnter Subject Name:";
                cin >> name;

                Subject subject;
                Subject *temp = subjects.search(name);
                subject = *temp;
                cout << "\nSelected Subject is:" << endl;
                subject.print();
                student->enrollSubject(subject);
                break;
            }
            case '3': {
                for (int i = 0; i < student->getSemester()[student->getCurrentSemester()].getSize(); i++) {
                    student->getSemester()[student->getCurrentSemester()].getSubjects()[i].print();
                    float marks;
                    cout << "\nSet marks of this Subject:";
                    cin >> marks;
                    student->getSemester()[student->getCurrentSemester()].getSubjects()[i].setMarks(marks);
                }
                break;
            }
            case '4': {
                student->calculateCGPA();
                student->print();
                for (int i = 0; i < student->getCurrentSemester(); i++) {
                    cout << "Semester " << i << endl;
                    student->getSemester()[i].print();
                }
                break;
            }
            case '5': {
                student->setCurrentSemester(student->getCurrentSemester() + 1);
                break;
            }
            case '0': {
                main();
                break;
            }
            default: {
                cout << "INVALID INPUT!!";
            }
        }
    }
}

int main() {
    string pass = "", user = "";
    cout << "\nEnter UserName:";
    cin >> user;
    cout << "\nEnter Password:";
    cin >> pass;

    if (pass == "admin" && user == "admin") {
        while (true) {
            menu();
        }
    } else {
        for (Student *temp = students.getHead(); temp != nullptr; temp = temp->getNext()) {
            if (user == temp->getName() && pass == temp->getRollNumber()) {
                StudentLogin(temp);
            }
        }
    }

    return 0;
}