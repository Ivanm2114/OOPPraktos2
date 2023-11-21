
#ifndef OOP_LABA4_STUDENTLEAF_H
#define OOP_LABA4_STUDENTLEAF_H

#endif //OOP_LABA4_STUDENTLEAF_H

#include <string>
#include "Date.h"

using namespace std;

class StudentLeaf {
public:
    StudentLeaf();

    StudentLeaf(string name, Date date);

    StudentLeaf(StudentLeaf const &leaf);

    void setNameAndDate(string name, Date date);

    bool canSetName(string name) const;

    bool operator==(const StudentLeaf &obj) const;

    bool canSetLeaf(const StudentLeaf *leaf) const;

    void setRightLeaf(StudentLeaf *leaf);

    void setLeftLeaf(StudentLeaf *leaf);

    string print() const;

    bool empty() const;

private:
    string studentName;
    Date lessonDate;
    StudentLeaf *leftStudent;
    StudentLeaf *rightStudent;
};
