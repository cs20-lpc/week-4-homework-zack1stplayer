#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "Course.hpp"
#include "LinkedList.hpp"

using namespace std;

class Student {
    protected:
        int id;
        string name;
        float gpa;
        LinkedList<Course> courseList;

        void copy(const Student&);

    public:
        Student();
        Student(Student&);
        Student(int, string, float);
        virtual ~Student();

        Student& operator=(const Student&);

        int getId() const;

        string getName() const;

        float getGpa() const;
        void setGpa(float);
        
        int getNumberOfCourses();
        bool hasCourses();

        Course getCourse(int);
        void addCourse(Course&);
        void removeCourse(int);
        
        friend ostream& operator<<(ostream&, Student&);
};

#include "Student.cpp"