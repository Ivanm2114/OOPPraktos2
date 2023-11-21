#ifndef LABA4_STUDENTTREE_H
#define LABA4_STUDENTTREE_H

#endif //LABA4_STUDENTTREE_H

#include "StudentLeaf.h"

class StudentTree {
public:
    StudentTree();

    StudentTree(StudentLeaf const &baseLeaf);

    StudentTree(StudentTree const &baseTree);

    void add(StudentLeaf leaf);

    void add(string name, Date date);

    bool canAdd(StudentLeaf leaf) const;

private:
    int counter;
    StudentLeaf base;
};
