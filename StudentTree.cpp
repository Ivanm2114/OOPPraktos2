#include "StudentTree.h"
#include <string>

using namespace std;

template <class T,class T2>
StudentTree<T,T2>::StudentTree() {
    counter = 0;
}

template <class T,class T2>
StudentTree<T,T2>::StudentTree(const StudentLeaf<T,T2> &baseLeaf) {
    counter = 1;
    base = StudentLeaf(baseLeaf);
}

template <class T,class T2>
bool StudentTree<T,T2>::canAdd(StudentLeaf<T,T2> leaf) const {
    return !leaf.empty();
}

template <class T,class T2>
void StudentTree<T,T2>::add(string name, Date date) {
    add(StudentLeaf(name, date));
}

template <class T,class T2>
void StudentTree<T,T2>::add(StudentLeaf<T,T2> leaf) {
    if(counter==0){
        base=StudentLeaf(leaf);
    }
    else{
        innerAdd(base, StudentLeaf(leaf));
    }
}

template <class T,class T2>
void StudentTree<T,T2>::innerAdd(StudentLeaf<T,T2> root, StudentLeaf<T,T2> leaf) {
    if(leaf.getDate()<root.getDate()){
        auto left=root.getLeftStudent();
        if(root.getLeftStudent()!= nullptr){
            innerAdd(*left,leaf);
        }
        else{
            root.setLeftLeaf(&leaf);
        }
    }
    else{
        auto right = root.getRightStudent();
        if(root.getRightStudent()!= nullptr){
            innerAdd(*right,leaf);
        }
        else{
            root.setRightLeaf(&leaf);
        }
    }
}

template <class T, class T2>
StudentTree<T,T2> ::~StudentTree() {
    delete base;
}
