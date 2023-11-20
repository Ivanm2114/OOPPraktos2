#include "StudentLeaf.h"

using namespace std;

StudentLeaf::StudentLeaf() {
    leftStudent= nullptr;
    rightStudent= nullptr;
    parentLeaf= nullptr;
    studentName = "";
    lessonDate = Date();
}

StudentLeaf::StudentLeaf(string name, Date date) {
    studentName=name;
    lessonDate=Date(date);
    leftStudent= nullptr;
    rightStudent= nullptr;
    parentLeaf= nullptr;
}

StudentLeaf::StudentLeaf(const StudentLeaf &leaf) {
    leftStudent= nullptr;
    rightStudent= nullptr;
    parentLeaf= nullptr;
    this->studentName=leaf.studentName;
    this->lessonDate=Date(leaf.lessonDate);
}