//
// Created by qasim khokhar on 1/5/20.
//

#ifndef COLLAGE_MANAGE_SYSTEM_STUDENTLIST_H
#define COLLAGE_MANAGE_SYSTEM_STUDENTLIST_H

#include "Student.h"
class StudentList {
private:
    Student *head;
    Student *tail;
public:
    StudentList();
    ~StudentList();

//  getters and setters
    Student *getHead() const;
    void setHead(Student *head);

    Student *getTail() const;
    void setTail(Student *tail);

//  methods
    bool isEmpty();
    void insertAtTail(Student student);

    Student *search(string rollNumber);
    void deleteNode(Student student);
    void print()const;


};


#endif //COLLAGE_MANAGE_SYSTEM_STUDENTLIST_H
