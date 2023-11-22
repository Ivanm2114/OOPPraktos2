#ifndef LABA4_STUDENTTREE_H
#define LABA4_STUDENTTREE_H

#endif //LABA4_STUDENTTREE_H
#include "Leaf.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class V,class K>
class Tree {
public:
    Tree();

    Tree(V data, K date);

    Tree(Leaf<V,K> const &baseLeaf);

    Tree(Tree<V,K> const &baseTree);

    ~Tree();

    void deleteAll();

    void add(Leaf<V,K> leaf);

    void add(V data, K date);

    void deleteValue(V name);

    string printTree();

    bool findKey(K date) const;

    ostream operator<< (ostream stream) const;

    int getCounter() const;

    bool canAdd(Leaf<V,K> leaf) const;

    bool operator==(Tree<V,K> &obj) const;


    V operator[](K date) const;

    void write2File(string path);

    void getFromFile(string path);

    Leaf<V,K>* findValue(V name) const;



private:
    void addChildren(Leaf<V,K> leaf);
    void innerAdd(Leaf<V,K> &root, Leaf<V,K> leaf);
    int counter=0;
    Leaf<V,K> base;
};



template<class V, class K>
Tree<V, K>::Tree() {
    counter = 0;
}

template<class V, class K>
Tree<V,K>::Tree(V data, K date) {
    add(data,date);
}

template<class V, class K>
Tree<V, K>::Tree(const Leaf<V, K> &baseLeaf) {
    add(Leaf<V,K>(baseLeaf));
}

template<class V, class K>
bool Tree<V, K>::canAdd(Leaf<V, K> leaf) const {
    return !leaf.empty();
}

template<class V, class K>
void Tree<V, K>::add(V name, K date) {
    add(Leaf(name, date));
}

template<class V, class K>
void Tree<V, K>::add(Leaf<V, K> leaf) {
    if (!findKey(leaf.getDate())) {
        if (canAdd(leaf)) {
            if (counter == 0) {
                base = Leaf(leaf);
            } else {
                innerAdd(base, leaf);
            }
            counter++;
        }
    }
}

template<class V, class K>
void Tree<V, K>::innerAdd(Leaf<V, K> &root, Leaf<V, K> leaf) {
    if (leaf.getDate() < root.getDate()) {
        auto left = root.getLeftLeaf();
        if (left != nullptr) {
            innerAdd(*left, leaf);
        } else {
            leaf.setParentLeaf(&root);
            root.setLeftLeaf(&leaf);

        }
    } else {
        auto right = root.getRightLeaf();
        if (right != nullptr) {
            innerAdd(*right, leaf);
        } else {
            leaf.setParentLeaf(&root);
            root.setRightLeaf(&leaf);
        }
    }

}

template<class V, class K>
void Tree<V, K>::addChildren(Leaf<V, K> leaf) {
    if (leaf != nullptr) {
        if (leaf.getRightLeaf() != nullptr) {
            add(leaf.getRightLeaf());
            addChildren(leaf.getRightLeaf());
        }
        if (leaf.getLeftLeaf() != nullptr) {
            add(leaf.getLeftLeaf());
            addChildren(leaf.getLeftLeaf());
        }
    }
}

template<class V, class K>
void Tree<V, K>::deleteAll() {
    base.~Leaf();
    counter = 0;
}

template<class V, class K>
Tree<V, K>::~Tree() {
}

template<class V, class K>
int Tree<V, K>::getCounter() const {
    return counter;
}

template<class V, class K>
bool Tree<V, K>::operator==(Tree<V, K> &obj) const {
    return base == obj.base;
}

template<class V, class K>
bool Tree<V, K>::findKey(K date) const {
    return this->operator[](date) != NULL;
}

template<class V, class K>
ostream Tree<V, K>::operator<<(std::ostream stream) const {
    stream << base;
}



template<class V, class K>
V Tree<V, K>::operator[](K date) const {
    const Leaf<V, K> *t = &base;
    K tDate = t->getDate();
    while (!(date == tDate) and t != nullptr) {
        tDate = t->getDate();
        if (date < tDate) { t = base.getLeftLeaf(); }
        else { t = base.getRightLeaf(); }
    }
    if (t != nullptr) return base.getData();
    return NULL;
}

template<class V, class K>
Leaf<V, K> *Tree<V, K>::findValue(V name) const {
    return base.searchValue(name);
}

template<class V, class K>
void Tree<V, K>::deleteValue(V name) {
    Leaf<V, K> *deleting = findValue(name);
    if (deleting != nullptr) {
        deleting->dropParentLeaf();
        addChildren(deleting);
        delete deleting;
    }
}

template<class V,class K>
Tree<V,K>::Tree(const Tree<V, K> &baseTree) {
    auto newBase=Leaf<V,K>(baseTree.base);
    add(newBase);
    addChildren(newBase);
}




template<class V,class K>
void Tree<V,K>::write2File(string path){
    fstream file(path);
    file << base.print();
    file.close();

}