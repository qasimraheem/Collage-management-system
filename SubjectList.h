//
// Created by qasim khokhar on 1/5/20.
//

#ifndef COLLAGE_MANAGE_SYSTEM_SUBJECTLIST_H
#define COLLAGE_MANAGE_SYSTEM_SUBJECTLIST_H

#include "Subject.h"
#include <string.h>
using namespace std;

class SubjectList {
    Subject *head;
    Subject *tail;
public:
    SubjectList();
    ~SubjectList();

    //methods
    bool isEmpty();
    void insertAtTail(Subject subject);
    Subject *search(string  name);
    Subject *preNodeSearch(string name);
    void deleteNode(string name);

    //getter & setter
    Subject *getHead() const;
    void setHead(Subject *head);

    Subject *getTail() const;
    void setTail(Subject *tail);

    void print();

};


#endif //COLLAGE_MANAGE_SYSTEM_SUBJECTLIST_H
