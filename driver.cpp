#include <iostream>
#include <string>
#include <sstream>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"

using namespace std;

void displayMenu() {
  cout << "1. Insert Student" << endl
       << "2. Delete Student" << endl
       << "3. Search Student" << endl
       << "4. Display All" << endl
       << "5. Count Students" << endl
       << "6. Add a course" << endl
       << "7. Exit" << endl
       << "Enter choice: " << flush;
}

template <typename T>
void getChoice(T& outVar) {
  string input;
  stringstream outStream;
  getline(cin, input);
  outStream << input;
  outStream >> outVar;
}

void getChoice(string& outVar) {
  getline(cin, outVar);
}

void insertStudent(LinkedList<Student>& stuList) {
  int inputInteger;
  string inputString;
  float inputFloat;
  // Student stu;
  bool flag = false;
  cout << "Enter ID: ";
  getChoice(inputInteger);
  cout << "Enter Name: ";
  getChoice(inputString);
  cout << "Enter GPA: ";
  getChoice(inputFloat);

  Student stu = Student(inputInteger, inputString, inputFloat);
  
  for (int i = 0; i < stuList.getLength(); i++)
  {
    if (stuList.getElement(i).getId() == inputInteger) {
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << "Failed to add student: Student with ID " << inputInteger << " already exists" << endl;
  } else {
    stuList.append(stu);
    cout << "Successfully added student with ID " << inputInteger << endl;
  }
  
}

void deleteStudent(LinkedList<Student>& stuList) {
  int inputInteger;
  bool flag = false;
  cout << "Enter ID to delete: ";
  getChoice(inputInteger);
  for (int i = 0; i < stuList.getLength(); i++)
  {
    if (stuList.getElement(i).getId() == inputInteger) {
      stuList.remove(i);
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << "Deleted student with ID " << inputInteger << endl;
  } else {
    cout << "Could not find student with ID " << inputInteger << endl;
  }
}

void searchStudent(LinkedList<Student>& stuList) {
  int inputInteger;
  bool flag = false;
  Student stu;
  cout << "Enter ID to search: ";
  getChoice(inputInteger);
  for (int i = 0; i < stuList.getLength(); i++)
  {
    if (stuList.getElement(i).getId() == inputInteger) {
      stu = stuList.getElement(i);
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << stu << endl;
  } else {
    cout << "Could not find student with ID " << inputInteger << endl;
  }
}

void displayStudents(LinkedList<Student>& stuList) {
  Student stu;
  cout << "All Students:" << endl;
  for (int i = 0; i < stuList.getLength(); i++)
  {
    stu = stuList.getElement(i);
    cout << " " << stu << endl;
  }
  if (stuList.isEmpty()) {
    cout << " None" << endl;
  }
}

void countStudents(LinkedList<Student>& stuList) {
  cout << "Number of Students: " << stuList.getLength() << endl;
}

void addCourse(LinkedList<Student>& stuList) {
  string inputString;
  int inputInteger;
  Course newCoruse;
  Student newStudent;
  bool flag;
  cout << "Enter Course Name: ";
  getChoice(inputString);
  cout << "Enter Room #: ";
  getChoice(inputInteger);

  newCoruse = Course(inputString, inputInteger);

  cout << "Enter Student ID: ";
  getChoice(inputInteger);
  for (int i = 0; i < stuList.getLength(); i++)
  {
    if (stuList.getElement(i).getId() == inputInteger) {
      newStudent = stuList.getElement(i);
      newStudent.addCourse(newCoruse);
      stuList.replace(newStudent, i);
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << "Course successfully added to student with ID " << inputInteger << endl;
  } else {
    cout << "Could not find student with ID " << inputInteger << endl;
  }

}

int main()
{
  // TO DO:
  // 

  int inputInteger;

  LinkedList<Student> rootList;

  do {
    displayMenu();
    getChoice(inputInteger);
    cout << endl;
    switch (inputInteger) {
    case 1:
      insertStudent(rootList);
      break;
    case 2:
      deleteStudent(rootList);
      break;
    case 3:
      searchStudent(rootList);
      break;
    case 4:
      displayStudents(rootList);
      break;
    case 5:
      countStudents(rootList);
      break;
    case 6:
      addCourse(rootList);
      break;
    case 7:
      cout << "Goodbye" << endl;
      break;
    
    default:
      cout << "Try again" << endl;
      break;
    }
  } while (inputInteger != 7);

}
