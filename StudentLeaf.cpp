#include "StudentLeaf.h"

using namespace std;

StudentLeaf::StudentLeaf() {
    leftStudent = nullptr;
    rightStudent = nullptr;
    studentName = "";
    lessonDate = Date();
}

StudentLeaf::StudentLeaf(string name, Date date) {
    studentName = name;
    lessonDate = Date(date);
    leftStudent = nullptr;
    rightStudent = nullptr;
}

StudentLeaf::StudentLeaf(const StudentLeaf &leaf) {
    leftStudent = nullptr;
    rightStudent = nullptr;
    this->studentName = leaf.studentName;
    this->lessonDate = Date(leaf.lessonDate);
}

bool StudentLeaf::canSetName(string name) const {
    return !name.empty();
}

void StudentLeaf::setNameAndDate(string name, Date date) {
    if (canSetName(name)) {
        studentName = name;
        lessonDate = Date(date);
    }
}

bool StudentLeaf::operator==(const StudentLeaf &obj) const {
    return this->studentName==obj.studentName and this->lessonDate==obj.lessonDate;
}


string StudentLeaf::print() const {
    return studentName+" "+lessonDate.print();
}

bool StudentLeaf::canSetLeaf(const StudentLeaf *leaf) const {
    return leaf!= nullptr;
}

void StudentLeaf::setRightLeaf(StudentLeaf *leaf) {
    if(canSetLeaf(leaf))
        rightStudent=leaf;
}

void StudentLeaf::setLeftLeaf(StudentLeaf *leaf) {
    if(canSetLeaf(leaf))
        leftStudent=leaf;
}

bool StudentLeaf::empty() const {
    return lessonDate.isnull() and studentName.empty();
}