//
// Created by qasim khokhar on 1/1/20.
//

#include "Semester.h"

Semester::Semester() {
    totalCreditHours = 0;
    subjects = nullptr;
    size = 0;
}

Semester::~Semester() {
    delete[] subjects;
}

int Semester::getTotalCreditHours() const {
    return totalCreditHours;
}

void Semester::setTotalCreditHours(int totalCreditHours) {
    Semester::totalCreditHours = totalCreditHours;
}

Subject *Semester::getSubjects() const {
    return subjects;
}

void Semester::setSubjects(Subject *subjects) {
    Semester::subjects = subjects;
}

void Semester::calculateCreditHours() {
    if (subjects != nullptr) {
        int result = 0;
        for (int i=0; i < size; i++) {
            Subject temp = subjects[i];
            result += temp.getCreditHours();
        }
        totalCreditHours = result;
    }
}

void Semester::enrollSubject(Subject subject) {
    if(totalCreditHours<18){
        if(subject.getCreditHours()+totalCreditHours<=18){
            size++;
            subjects=new Subject[size];
            subjects[size-1]=subject;
            cout<<"Subject Added"<<endl;
        }else{
            cout<<"Subject CreditHours over weight"<<endl;
        }
    } else{
        cout<<"Total CreditHours are Full"<<endl;
    }
}

float Semester::getGpa() const {
    return GPA;
}

void Semester::setGpa(float gpa) {
    GPA = gpa;
}

void Semester::print() const{
    cout<<"TotalCreditHours:"<<totalCreditHours<<endl;
    cout<<"GPA:"<<GPA<<endl;
    for(int i=0;i<size;i++){
        this->subjects[i].printList();
    }

}
void Semester::calculateGPA(){
    float gpa=0;
    float tmarks=0.0,tt=0.0;
    for(int i=0;i<size;i++){
        tmarks+=this->subjects[i].getMarks();
        tt+=100;
    }
    gpa=(tmarks/tt)*4;

}

int Semester::getSize() const {
    return size;
}

void Semester::setSize(int size) {
    Semester::size = size;
}
