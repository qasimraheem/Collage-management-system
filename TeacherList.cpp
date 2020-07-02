//
// Created by qasim khokhar on 1/5/20.
//

#include "TeacherList.h"

TeacherList::TeacherList() {
    head= nullptr;
    tail= nullptr;
}

TeacherList::~TeacherList() {
    delete head;
    delete tail;

}

Teacher *TeacherList::getHead() const {
    return head;
}

void TeacherList::setHead(Teacher *head) {
    TeacherList::head = head;
}

Teacher *TeacherList::getTail() const {
    return tail;
}

void TeacherList::setTail(Teacher *tail) {
    TeacherList::tail = tail;
}


bool TeacherList::isEmpty() {
    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}

void TeacherList::insertAtTail(Teacher teacher) {
    if(this->isEmpty()){
        Teacher *temp=new Teacher(teacher);
        head=temp;
        tail=temp;
    }else{
        Teacher *temp=new Teacher(teacher);
        tail->setNext(temp);
        tail=temp;
    }
}
Teacher* TeacherList::search(string name) {
    for(Teacher *i=this->getHead();i!= nullptr;i=i->getNext()){
        if(i->getName()==name){
            return i;
        }
    }
    return nullptr;
}

Teacher *TeacherList::preNodeSearch(string name) {
    Teacher *preNode= nullptr;
    for(Teacher *i=this->getHead();i!= nullptr;i=i->getNext()){
        if(i->getName()==name){
            return preNode;
        } else{
            preNode=i;
        }
    }
    return nullptr;
}

void TeacherList::deleteNode(string name) {
    Teacher *preNode=preNodeSearch(name);
    Teacher *temp=search(name);
    if(temp!= nullptr){
        if(temp==head){
            this->setHead(temp->getNext());
//            temp->setNext(nullptr);

            delete temp;
        }else if(temp==tail){
            preNode->setNext(nullptr);
            this->setTail(preNode);
            temp->setNext(nullptr);
            delete temp;
        }else{
            preNode->setNext(temp->getNext());
            temp->setNext(nullptr);
            delete temp;
        }
    }

}

void TeacherList::print(){
    for (Teacher *i = head; i!= nullptr  ; i=i->getNext()) {
        i->printList();
    }
}