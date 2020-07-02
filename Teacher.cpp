//
// Created by qasim khokhar on 1/1/20.
//

#include "Teacher.h"

Teacher::Teacher(const string &name, const string &gender) : name(name), gender(gender) {
    next= nullptr;
}

Teacher::~Teacher() {
delete next;
}

Teacher::Teacher() {
    next= nullptr;
}

const string &Teacher::getName() const {
    return name;
}

void Teacher::setName(const string &name) {
    Teacher::name = name;
}

const string &Teacher::getGender() const {
    return gender;
}

void Teacher::setGender(const string &gender) {
    Teacher::gender = gender;
}

float Teacher::getSalary() const {
    return salary;
}

void Teacher::setSalary(float salary) {
    Teacher::salary = salary;
}

long Teacher::getNumber() const {
    return number;
}

void Teacher::setNumber(long number) {
    Teacher::number = number;
}

const string &Teacher::getEmail() const {
    return email;
}

void Teacher::setEmail(const string &email) {
    Teacher::email = email;
}

void Teacher::print() {
    cout<<"Name:"<<name<<endl;
    cout<<"Gender:"<<gender<<endl;
    cout<<"Email:"<<email<<endl;
    cout<<"Number:"<<number<<endl;
    cout<<"Salary:"<<salary<<endl;
}
void Teacher::printList() {
    cout<<"Name:"<<name<<"\tGender:"<<gender<<"\tEmail:"<<email<<"\tNumber:"<<number<<"\tSalary:"<<salary<<endl;
}

Teacher *Teacher::getNext() const {
    return next;
}

void Teacher::setNext(Teacher *next) {
    Teacher::next = next;
}

Teacher::Teacher(const string &name, const string &gender, float salary, long number, const string &email) : name(name),
                                                                                                             gender(gender),
                                                                                                             salary(salary),
                                                                                                             number(number),
                                                                                                             email(email) {
    next= nullptr;
}
