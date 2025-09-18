#include "Student.hpp"

Student::Student() {
    this->id = 0; this->name = "null"; this->gpa = 0.0;
    this->courseList = LinkedList<Course>();
}

Student::Student(Student& copyObj) {
    copy(copyObj);
}

Student::Student(int uId, string uName, float uGpa) {
    this->id = uId; this->name = uName; this->gpa = uGpa;
    this->courseList = LinkedList<Course>();
}

Student::~Student() {
    this->id = 0;
    this->name.clear();
    this->gpa = 0.0;
    if (!this->courseList.isEmpty()) {
        this->courseList.clear();
    }
}

Student& Student::operator=(const Student& rightObj) {
    if (this != &rightObj) {
        copy(rightObj);
    }
    return *this;
}

void Student::copy(const Student& copyObj) {
    this->id = copyObj.id; this->name = copyObj.name; this->gpa = copyObj.gpa;
    if (!this->courseList.isEmpty()) {
        this->courseList.clear();
    }
    this->courseList = copyObj.courseList;
}

int Student::getId() const {
    return this->id;
}

string Student::getName() const {
    return this->name;
}

float Student::getGpa() const {
    return this->gpa;
}

void Student::setGpa(float uGpa) {
    this->gpa = uGpa;
}

int Student::getNumberOfCourses() {
    return this->courseList.getLength();
}

bool Student::hasCourses() {
    return !this->courseList.isEmpty();
}

Course Student::getCourse(int pos) {
    return this->courseList.getElement(0);
}

void Student::addCourse(Course& elem) {
    this->courseList.append(elem);
}

void Student::removeCourse(int pos) {
    this->courseList.remove(pos);
}

ostream& operator<<(ostream& outStream, Student& myObj) {
    outStream << myObj.id << " " << myObj.name << " " << myObj.gpa << " Courses: ";
    if (myObj.hasCourses()) {
        for (int i = 0; i < myObj.getNumberOfCourses(); i++) {
            outStream << myObj.getCourse(i);
            if (i < (myObj.getNumberOfCourses() - 1)) {
                outStream << " | ";
            }
        }
    } else {
        outStream << "None";
    }
    outStream << " ";
    return outStream;
}