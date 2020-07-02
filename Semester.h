//
// Created by qasim khokhar on 1/1/20.
//

#ifndef COLLAGE_MANAGE_SYSTEM_SEMESTER_H
#define COLLAGE_MANAGE_SYSTEM_SEMESTER_H

#include "Subject.h"

class Semester {
private:
    int totalCreditHours;
    Subject *subjects;
    int size;
    float GPA;

public:
    Semester();
    virtual ~Semester();

    int getTotalCreditHours() const;
    void setTotalCreditHours(int totalCreditHours);

    int getSize() const;

    void setSize(int size);

    Subject *getSubjects() const;
    void setSubjects(Subject *subjects);

    float getGpa() const;
    void setGpa(float gpa);

    void calculateCreditHours();
    void enrollSubject(Subject subject);

    void print() const;
    void calculateGPA();

};


#endif //COLLAGE_MANAGE_SYSTEM_SEMESTER_H
