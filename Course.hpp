#pragma once

#include <string>
#include <iostream>

using namespace std;

class Course {
    protected:
        string name;
        int location;   // Room #

        void copy(const Course&);

    public:
        Course();
        Course(string, int);
        virtual ~Course();
        
        Course& operator=(const Course&);

        string getName();

        int getLocation();

        friend ostream& operator<<(ostream&, const Course&);
};

#include "Course.cpp"