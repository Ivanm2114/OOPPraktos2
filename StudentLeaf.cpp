#include "StudentLeaf.h"

using namespace std;

template <class T, class T2>
StudentLeaf<T,T2>::StudentLeaf(T data, T2 date) {
    this->data = data;
    lessonDate = Date(date);
    leftLeaf = nullptr;
    rightLeaf = nullptr;
}

template <class T, class T2>
StudentLeaf<T,T2>::StudentLeaf(const StudentLeaf &leaf) {
    leftLeaf = nullptr;
    rightLeaf = nullptr;
    this->studentName = leaf.studentName;
    this->lessonDate = T2(leaf.lessonDate);
}

template <class T, class T2>
bool StudentLeaf<T,T2>::canSetData(T data) const {
    return data==NULL;
}

template <class T, class T2>
void StudentLeaf<T,T2>::setDataAndDate(T data, T2 date) {
    if (canSetName(data)) {
        this->data = data;
        lessonDate = T2(date);
    }
}

template <class T, class T2>
bool StudentLeaf<T,T2>::operator==(const StudentLeaf &obj) const {
    return this->studentName==obj.studentName and this->lessonDate==obj.lessonDate;
}

template <class T, class T2>
string StudentLeaf<T,T2>::print() const {
    return data+" "+lessonDate.print();
}

template <class T, class T2>
bool StudentLeaf<T,T2>::canSetLeaf(const StudentLeaf<T,T2> *leaf) const {
    return leaf!= nullptr;
}

template <class T, class T2>
void StudentLeaf<T,T2>::setRightLeaf(StudentLeaf<T,T2> *leaf) {
    if(canSetLeaf(leaf))
        rightLeaf=leaf;
}

template <class T, class T2>
void StudentLeaf<T,T2>::setLeftLeaf(StudentLeaf<T,T2> *leaf) {
    if(canSetLeaf(leaf))
        leftLeaf=leaf;
}

template <class T, class T2>
bool StudentLeaf<T,T2>::empty() const {
    return lessonDate.isnull() and data==NULL;
}

template <class T, class T2>
T2 StudentLeaf<T,T2>::getDate() const{
    return lessonDate;
}


template <class T, class T2>
T StudentLeaf<T,T2>::getData() const {
    return data;
}

template <class T, class T2>
StudentLeaf<T,T2>* StudentLeaf<T,T2>::getLeftLeaf() const {
    return leftLeaf;
}

template <class T, class T2>
StudentLeaf<T,T2>* StudentLeaf<T,T2>::getRightLeaf() const {
    return rightLeaf;
}

template<class T, class T2>
StudentLeaf<T, T2>::~StudentLeaf() {
    delete rightLeaf;
    delete leftLeaf;
}
