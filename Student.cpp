//
// Created by qasim khokhar on 1/1/20.
//

#include "Student.h"

Student::Student(const string &name, int age, long number, const string &email, const string &rollNumber) {
    this->name=name;
    this->age=age;
    this->number=number;
    this->email=email;
    this->rollNumber=rollNumber;
    this->CGPA=0;
    this->currentSemester=0;
    next= nullptr;
    previous= nullptr;
}

Student::Student() {
    this->name="";
    this->age=0;
    this->number=0;
    this->email="";
    this->rollNumber="";
    this->CGPA=0;
    this->currentSemester=0;
    next= nullptr;
    previous= nullptr;
}

Student::~Student() {
    delete next;
    delete previous;
}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

int Student::getAge() const {
    return age;
}

void Student::setAge(int age) {
    Student::age = age;
}

long Student::getNumber() const {
    return number;
}

void Student::setNumber(long number) {
    Student::number = number;
}

const string &Student::getEmail() const {
    return email;
}

void Student::setEmail(const string &email) {
    Student::email = email;
}

const string &Student::getRollNumber() const {
    return rollNumber;
}

void Student::setRollNumber(const string &rollNumber) {
    Student::rollNumber = rollNumber;
}

float Student::getCgpa() const {
    return CGPA;
}

void Student::setCgpa(float cgpa) {
    CGPA = cgpa;
}

const Semester *Student::getSemester() const {
    return semester;
}

int Student::getCurrentSemester() const {
    return currentSemester;
}

void Student::setCurrentSemester(int currentSemester) {
    Student::currentSemester = currentSemester;
}

void Student::print() {
    cout<<"Name:"<<name<<endl;
    cout<<"Age:"<<age<<endl;
    cout<<"Number:"<<number<<endl;
    cout<<"Email:"<<email<<endl;
    cout<<"RollNumber"<<rollNumber<<endl;
    cout<<"CGPA:"<<CGPA<<endl;
    cout<<"CurrentSemester:"<<currentSemester<<endl;
}

void Student::printList() {
    cout<<"Name:"<<name<<"\tAge:"<<age<<"\tNumber:"<<number<<"\tEmail:"<<email<<"\tRollNumber:"<<rollNumber<<"\tCGPA:"<<CGPA<<"\tCurrentSemester:"<<currentSemester<<endl;
}

Student *Student::getNext() const {
    return next;
}

void Student::setNext(Student *next) {
    Student::next = next;
}

Student *Student::getPrevious() const {
    return previous;
}

void Student::setPrevious(Student *previous) {
    Student::previous = previous;
}

void Student::enrollSubject(Subject subject) {
    semester[currentSemester].enrollSubject(subject);
}

void Student::calculateCGPA() {
    float cgpa=0.0;
    for(int i=0;i<currentSemester;i++){
        semester[i].calculateGPA();
        cgpa+=semester[i].getGpa();
    }
    cgpa=cgpa/currentSemester;
}
