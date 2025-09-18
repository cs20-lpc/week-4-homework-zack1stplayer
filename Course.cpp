#include "Course.hpp"

Course::Course() {
    this->name = "null";
    this->location = 0;
}

Course::Course(string uName, int uLocation) : name(uName), location(uLocation) { }

Course::~Course() {
    this->name.clear();
    this->location = 0;
}

Course& Course::operator=(const Course& rightObj) {
    if (this != &rightObj) {
        copy(rightObj);
    }
    return *this;
}

void Course::copy(const Course& copyObj) {
    this->name = copyObj.name;
    this->location = copyObj.location;
}

string Course::getName() {
    return this->name;
}

int Course::getLocation() {
    return this->location;
}

ostream& operator<<(ostream& outStream, const Course& myObj) {
    outStream << myObj.name << " : " << myObj.location;
    return outStream;
}