#ifndef LABA4_STUDENTTREE_H
#define LABA4_STUDENTTREE_H

#endif //LABA4_STUDENTTREE_H

#include "StudentLeaf.h"

template <class T,class T2>
class StudentTree {
public:
    StudentTree();

    StudentTree(StudentLeaf<T,T2> const &baseLeaf);

    StudentTree(StudentTree const &baseTree);

    ~StudentTree();



    void add(StudentLeaf<T,T2> leaf);

    void add(string name, Date date);

    bool canAdd(StudentLeaf<T,T2> leaf) const;



private:
    void innerAdd(StudentLeaf<T,T2> root,StudentLeaf<T,T2> leaf);
    int counter;
    StudentLeaf<T,T2> base;
};
