//
// Created by qasim khokhar on 1/1/20.
//

#include "Subject.h"
#include <iostream>
using namespace std;

const string &Subject::getName() const {
    return name;
}

void Subject::setName(const string &name) {
    Subject::name = name;
}

const Teacher &Subject::getTeacher() const {
    return teacher;
}

void Subject::setTeacher(const Teacher &teacher) {
    Subject::teacher = teacher;
}

int Subject::getCreditHours() const {
    return creditHours;
}

void Subject::setCreditHours(int creditHours) {
    Subject::creditHours = creditHours;
}

float Subject::getFees() const {
    return fees;
}

void Subject::setFees(float fees) {
    Subject::fees = fees;
}

float Subject::getMarks() const {
    return marks;
}

void Subject::setMarks(float marks) {
    Subject::marks = marks;
}

Subject::Subject() {
    name="";
    creditHours=0;
    fees=0.0;
    marks=0.0;
    next=nullptr;
}

Subject::~Subject() {
    delete next;
}

Subject::Subject(string name, int creditHours, float fees,Teacher teacher){
    this->name=name;
    this->creditHours=creditHours;
    this->fees=fees;
    this->teacher=teacher;
    next=nullptr;
}

void Subject::print() {
    cout<<"Name:"<<name<<endl;
    cout<<"CreditHours:"<<creditHours<<endl;
    cout<<"Fees:"<<fees<<endl;
    cout<<"Marks:"<<marks<<endl;
    cout<<"Teacher:"<<teacher.getName()<<endl;

}
void Subject::printList() {
    cout<<"Name:"<<name<<"\tCreditHours:"<<creditHours<<"\tFees:"<<fees<<"\tMarks:"<<marks<<"\tTeacher:"<<teacher.getName()<<endl;
}

void Subject::setMarks1(float marks) {
    Subject::marks = marks;
}

Subject *Subject::getNext() const {
    return next;
}

void Subject::setNext(Subject *next) {
    Subject::next = next;
}
