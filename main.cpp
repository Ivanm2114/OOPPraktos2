#include <iostream>
#include <string>
#include "StudentLeaf.h"

using namespace std;


class StudentTree {
public:
    StudentTree();

    StudentTree(StudentLeaf const &baseLeaf);

    StudentTree(StudentTree const &baseLeaf);

    void add(StudentLeaf leaf);


};


int main() {


    return 0;
}
