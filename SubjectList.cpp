//
// Created by qasim khokhar on 1/5/20.
//

#include "SubjectList.h"
//
// Created by qasim khokhar on 1/5/20.
//

#include "SubjectList.h"

SubjectList::SubjectList() {
    head= nullptr;
    tail= nullptr;
}

SubjectList::~SubjectList() {
    delete head;
    delete tail;

}

Subject *SubjectList::getHead() const {
    return head;
}

void SubjectList::setHead(Subject *head) {
    SubjectList::head = head;
}

Subject *SubjectList::getTail() const {
    return tail;
}

void SubjectList::setTail(Subject *tail) {
    SubjectList::tail = tail;
}


bool SubjectList::isEmpty() {
    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}

void SubjectList::insertAtTail(Subject subject) {
    if(this->isEmpty()){
        Subject *temp=new Subject(subject);
        head=temp;
        tail=temp;
    }else{
        Subject *temp=new Subject(subject);
        tail->setNext(temp);
        tail=temp;
    }
}
Subject *SubjectList::search(string name) {
    for(Subject *i=this->getHead();i!= nullptr;i=i->getNext()){
        if(i->getName()==name){
            return i;
        }
    }
    return nullptr;
}

Subject *SubjectList::preNodeSearch(string name) {
    Subject *preNode= nullptr;
    for(Subject *i=this->getHead();i!= nullptr;i=i->getNext()){
        if(i->getName()==name){
            return preNode;
        } else{
            preNode=i;
        }
    }
    return nullptr;
}

void SubjectList::deleteNode(string name) {
    Subject *preNode=preNodeSearch(name);
    Subject *temp=search(name);
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

void SubjectList::print(){
    for (Subject *i = head; i!= nullptr  ; i=i->getNext()) {
        i->printList();
    }
}