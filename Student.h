//
// Created by qasim khokhar on 1/1/20.
//

#ifndef COLLAGE_MANAGE_SYSTEM_STUDENT_H
#define COLLAGE_MANAGE_SYSTEM_STUDENT_H

#import "Semester.h"
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    long int number;
    string email;
    string rollNumber;
    float CGPA;
    Semester semester[8];
    int currentSemester;
    Student* next= nullptr;
    Student* previous= nullptr;
public:
    Student(const string &name, int age, long number, const string &email, const string &rollNumber);
    Student();
    virtual ~Student();

    Student *getNext() const;

    void setNext(Student *next);

    Student *getPrevious() const;

    void setPrevious(Student *previous);

    const string &getName() const;
    void setName(const string &name);
    int getAge() const;
    void setAge(int age);
    long getNumber() const;
    void setNumber(long number);
    const string &getEmail() const;
    void setEmail(const string &email);
    const string &getRollNumber() const;
    void setRollNumber(const string &rollNumber);
    float getCgpa() const;
    void setCgpa(float cgpa);
    const Semester *getSemester() const;
    int getCurrentSemester() const;
    void setCurrentSemester(int currentSemester);

    void print();
    void printList();
    void calculateCGPA();
    void enrollSubject(Subject subject);
    void completeSemester();


};


#endif //COLLAGE_MANAGE_SYSTEM_STUDENT_H
