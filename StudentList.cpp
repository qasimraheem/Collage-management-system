//
// Created by qasim on 11/17/18.
//

#include "StudentList.h"

StudentList::StudentList() {
    this->head= nullptr;
    this->tail= nullptr;
}

StudentList::~StudentList() {
    this->tail= nullptr;
    this->head= nullptr;
}

Student *StudentList::getHead() const {
    return head;
}

void StudentList::setHead(Student *head) {
    StudentList::head = head;
}

Student *StudentList::getTail() const {
    return tail;
}

void StudentList::setTail(Student *tail) {
    StudentList::tail = tail;
}

bool StudentList::isEmpty() {
    if(this->head== nullptr){
        return true;
    }else{
        return false;
    }
}

void StudentList::insertAtTail(Student student) {
    if(isEmpty()){
        Student *temp=new Student(student);
        this->head=temp;
        this->tail=temp;
    }else{
        Student *temp=new Student(student);
        temp->setPrevious(tail);
        this->tail->setNext(temp);
        this->tail=temp;
    }
}

Student *StudentList::search(string rollNumber) {
    for(Student *temp=head;temp!= nullptr;temp=temp->getNext()){
        if(temp->getRollNumber()==rollNumber){
            return temp;
        }
    }
    return nullptr;
}

void StudentList::deleteNode(Student student) {
    Student *temp=search(student.getRollNumber());
    if(temp!= nullptr){
        if(temp==head){
            temp->getNext()->setPrevious(nullptr);
            head=temp->getNext();
            delete temp;
            temp= nullptr;
        }else if(temp==tail){
            temp->getPrevious()->setNext(nullptr);
            tail=temp->getPrevious();
            delete temp;
            temp = nullptr;
        }else{
            temp->getPrevious()->setNext(temp->getNext());
            temp->getNext()->setPrevious(temp->getPrevious());
            delete temp;
            temp= nullptr;
        }
    }
}

void StudentList::print() const {
    for(Student *i=this->head;i!=nullptr;i=i->getNext()){
        i->printList();
    }

}
