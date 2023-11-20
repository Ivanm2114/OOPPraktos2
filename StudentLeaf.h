
#ifndef OOP_LABA4_STUDENTLEAF_H
#define OOP_LABA4_STUDENTLEAF_H

#endif //OOP_LABA4_STUDENTLEAF_H
#include <string>
#include "Date.h"

using namespace std;

class StudentLeaf{
public:
    StudentLeaf();
    StudentLeaf(string name, Date date);
    StudentLeaf(StudentLeaf const &leaf);
    void setName(string name);
    void setDate(Date date);
    void setNameAndDate(string name, Date date);
    bool canSetName(string name) const;
    void canSetDate(Date date) const;
private:
    string studentName;
    Date lessonDate;
    StudentLeaf *leftStudent;
    StudentLeaf *rightStudent;
    StudentLeaf *parentLeaf;
};
