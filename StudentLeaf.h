
#ifndef OOP_LABA4_STUDENTLEAF_H
#define OOP_LABA4_STUDENTLEAF_H

#endif //OOP_LABA4_STUDENTLEAF_H

#include <string>
#include "Date.h"

using namespace std;
template <class T, class T2>
class StudentLeaf {
public:
    StudentLeaf();

    StudentLeaf(T data, T2 date);

    StudentLeaf(StudentLeaf const &leaf);

    ~StudentLeaf();

    void setDataAndDate(T data, T2 date);

    bool canSetData(T data) const;

    bool operator==(const StudentLeaf &obj) const;

    bool canSetLeaf(const StudentLeaf *leaf) const;

    void setRightLeaf(StudentLeaf *leaf);

    void setLeftLeaf(StudentLeaf *leaf);

    string print() const;

    bool empty() const;

    T2 getDate() const;

    StudentLeaf* getLeftLeaf() const;

    StudentLeaf* getRightLeaf() const;

    T getData() const;

private:
    T data;
    T2 lessonDate;
    StudentLeaf<T,T2> *leftLeaf= nullptr;
    StudentLeaf<T,T2> *rightLeaf= nullptr;
};

