//
// Created by qasim khokhar on 1/1/20.
//

#ifndef COLLAGE_MANAGE_SYSTEM_SUBJECT_H
#define COLLAGE_MANAGE_SYSTEM_SUBJECT_H

#include "Teacher.h"
#include <string>
using namespace std;

class Subject {
private:
    string name;
    Teacher teacher;
    int creditHours;
    float fees;
    float marks;
    Subject *next=nullptr;

public:
    Subject();
    Subject(string name,int creditHours, float fees,Teacher teacher);
    ~Subject();

    void setMarks1(float marks);

    Subject *getNext() const;

    void setNext(Subject *next);

    const string &getName() const;
    void setName(const string &name);

    const Teacher &getTeacher() const;
    void setTeacher(const Teacher &teacher);

    int getCreditHours() const;
    void setCreditHours(int creditHours);

    float getFees() const;
    void setFees(float fees);

    float getMarks() const;
    void setMarks(float marks);

    void print();
    void printList();
};


#endif //COLLAGE_MANAGE_SYSTEM_SUBJECT_H
