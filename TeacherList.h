//
// Created by qasim khokhar on 1/5/20.
//

#ifndef COLLAGE_MANAGE_SYSTEM_TEACHERLIST_H
#define COLLAGE_MANAGE_SYSTEM_TEACHERLIST_H

#include <iostream>
#include "Teacher.h"
using namespace std;

class TeacherList {
private:
    Teacher *head;
    Teacher *tail;
public:
    TeacherList();
    ~TeacherList();

    //methods
    bool isEmpty();
    void insertAtTail(Teacher teacher);
    Teacher *search(string  name);
    Teacher *preNodeSearch(string name);
    void deleteNode(string name);

    //getter & setter
    Teacher *getHead() const;
    void setHead(Teacher *head);

    Teacher *getTail() const;
    void setTail(Teacher *tail);

    void print();

};


#endif //COLLAGE_MANAGE_SYSTEM_TEACHERLIST_H
