#include "StudentTree.h"
#include <string>

using namespace std;

StudentTree::StudentTree() {
    counter=0;
    base=StudentLeaf();
}

StudentTree::StudentTree(const StudentLeaf &baseLeaf) {
    counter=1;
    base=StudentLeaf(baseLeaf);
}

bool StudentTree::canAdd(StudentLeaf leaf) const {
    return !leaf.empty();
}

