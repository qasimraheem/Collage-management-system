//
// Created by qasim khokhar on 1/1/20.
//

#ifndef COLLAGE_MANAGE_SYSTEM_TEACHER_H
#define COLLAGE_MANAGE_SYSTEM_TEACHER_H

#include <iostream>
#include <string>
using namespace std;
class Teacher {
private:
    string name;
    string gender;
    float salary;
    long int number;
    string email;
    Teacher *next= nullptr;
public:
    Teacher(const string &name, const string &gender, float salary, long number, const string &email);

    Teacher(const string &name, const string &gender);
    Teacher();
    virtual ~Teacher();

    const string &getName() const;
    void setName(const string &name);
    const string &getGender() const;
    void setGender(const string &gender);
    float getSalary() const;
    void setSalary(float salary);
    long getNumber() const;
    void setNumber(long number);
    const string &getEmail() const;
    void setEmail(const string &email);

    Teacher *getNext() const;

    void setNext(Teacher *next);

    void print();
    void printList();
};


#endif //COLLAGE_MANAGE_SYSTEM_TEACHER_H
