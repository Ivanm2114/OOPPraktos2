#ifndef LABA4_STUDENTTREE_H
#define LABA4_STUDENTTREE_H

#endif //LABA4_STUDENTTREE_H

#include "Leaf.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class V, class K>
class Tree {
public:
    Tree();

    Tree(V data, K date);

    Tree(string path);

    Tree(Leaf<V, K> const &baseLeaf);

    Tree(Tree<V, K> &baseTree);

    ~Tree();

    void deleteAll();

    void add(Leaf<V, K> leaf);

    void add(V name, K date);

    void deleteValue(V name);

    string printTree() const;

    bool findKey(K date) const;

    int getCounter() const;

    bool canAdd(Leaf<V, K> leaf) const;

    bool operator==(Tree<V, K> &obj) const;

    Tree<V, K> *operator&&(Tree<V, K> &scndTree);

    V operator[](K date) const;

    void write2File(string path) const;

    void getFromFile(string path);

    Leaf<V, K> *findValue(V name) const;


private:
    void recursiveCheck(Leaf<V, K> *leaf, Tree<V, K> &checkTree, Tree<V, K> *addingTree);

    void addChildren(Leaf<V, K> *leaf);

    void innerAdd(Leaf<V, K> *root, Leaf<V, K> leaf);

    int counter = 0;
    Leaf<V, K> *base = nullptr;
};


template<class V, class K>
Tree<V, K>::Tree() {
    counter = 0;
}

template<class V, class K>
Tree<V, K>::Tree(V data, K date) {
    add(data, date);
}

template<class V, class K>
Tree<V, K>::Tree(const Leaf<V, K> &baseLeaf) {
    add(Leaf<V, K>(baseLeaf));
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
    if (canAdd(leaf)) {
        if (counter == 0) {
            base = new Leaf(leaf);
            counter++;
        } else if (!findKey(leaf.getDate())) {
            {
                innerAdd(base, leaf);
                counter++;
            }

        }

    }
}

template<class V, class K>
void Tree<V, K>::innerAdd(Leaf<V, K> *root, Leaf<V, K> leaf) {
    if (leaf.getDate() < root->getDate()) {
        Leaf<V, K> *left = root->getLeftLeaf();
        if (left != nullptr) {
            innerAdd(left, leaf);
        } else {
            Leaf<V, K> *newLeaf = new Leaf(leaf);
            newLeaf->setParentLeaf(root);
            root->setLeftLeaf(newLeaf);

        }
    } else {
        Leaf<V, K> *right = root->getRightLeaf();
        if (right != nullptr) {
            innerAdd(right, leaf);
        } else {
            Leaf<V, K> *newLeaf = new Leaf(leaf);
            newLeaf->setParentLeaf(root);
            root->setRightLeaf(newLeaf);
        }
    }

}

template<class V, class K>
void Tree<V, K>::addChildren(Leaf<V, K> *leaf) {
    if (leaf != nullptr) {
        if (leaf->getRightLeaf() != nullptr) {
            add(*leaf->getRightLeaf());
            addChildren(leaf->getRightLeaf());
        }
        if (leaf->getLeftLeaf() != nullptr) {
            add(*leaf->getLeftLeaf());
            addChildren(leaf->getLeftLeaf());
        }
    }
}

template<class V, class K>
void Tree<V, K>::deleteAll() {
    delete base;
    base = nullptr;
    counter = 0;
}

template<class V, class K>
Tree<V, K>::~Tree() {
    if (base != nullptr)
        delete base;
}

template<class V, class K>
int Tree<V, K>::getCounter() const {
    return counter;
}

template<class V, class K>
bool Tree<V, K>::operator==(Tree<V, K> &obj) const {
    if (base == nullptr and obj.base != nullptr or base != nullptr and obj.base == nullptr) return false;
    if (counter == 0 and obj.getCounter() == 0) return true;
    if (counter != obj.getCounter()) return false;
    return *base == *obj.base;
}

template<class V, class K>
bool Tree<V, K>::findKey(K date) const {
    return this->operator[](date) != "";
}


template<class V, class K>
V Tree<V, K>::operator[](K date) const {
    auto t = base;
    K tDate = t->getDate();
    while (t != nullptr and !(date == tDate)) {
        if (date < tDate) { t = t->getLeftLeaf(); }
        else { t = t->getRightLeaf(); }
        if (t != nullptr) tDate = t->getDate();

    }
    if (t != nullptr) return t->getData();
    return "";
}

template<class V, class K>
Leaf<V, K> *Tree<V, K>::findValue(V name) const {
    return base->searchValue(name);
}

template<class V, class K>
void Tree<V, K>::deleteValue(V name) {
    Leaf<V, K> *deleting = findValue(name);
    if (deleting != nullptr) {
        if (deleting != base) {
            deleting->dropParentLeaf();
            addChildren(deleting);
        } else {
            if (base->getRightLeaf()!= nullptr) {
                base = base->getRightLeaf();
                if(deleting->getLeftLeaf()!= nullptr)
                deleting->getLeftLeaf()->setParentLeaf(base);
            } else base = base->getLeftLeaf();
            if(base!= nullptr)
            base->dropParentLeaf();
        }
        --counter;
        delete deleting;
    }
}


template<class V, class K>
void Tree<V, K>::write2File(string path) const {
    ofstream file(path);
    if (base != nullptr)
        file << base->write2File();
    file.close();

}

template<class V, class K>
string Tree<V, K>::printTree() const {
    if (counter)
        return base->print(' ') + '\n';
    return "Tree is empty";

}

template<class V, class K>
void Tree<V, K>::getFromFile(string path) {
    ifstream file(path);
    string data, date;
    if (file.is_open()) {
        while (!file.eof()) {
            file >> data >> date;
            add(data, K(date));
        }

    }
}

template<class V, class K>
Tree<V, K>::Tree(std::string path) {
    getFromFile(path);
}

template<class V, class K>
Tree<V, K>::Tree(Tree<V, K> &baseTree) {
    add(*baseTree.base);
    addChildren(baseTree.base);
}


template<class V, class K>
Tree<V, K> *Tree<V, K>::operator&&(Tree<V, K> &scndTree) {
    auto rez = new Tree<V, K>();
    if (base != nullptr and scndTree.base != nullptr)
        recursiveCheck(base, scndTree, rez);
    return rez;

}

template<class V, class K>
void Tree<V, K>::recursiveCheck(Leaf<V, K> *leaf, Tree<V, K> &checkTree, Tree<V, K> *addingTree) {
    auto tdate = leaf->getDate();
    auto tdata = checkTree[tdate];
    if (tdata != "" and tdata == leaf->getData()) {
        addingTree->add(*leaf);
    }
    if (leaf->getRightLeaf() != nullptr) recursiveCheck(leaf->getRightLeaf(), checkTree, addingTree);
    if (leaf->getLeftLeaf() != nullptr) recursiveCheck(leaf->getLeftLeaf(), checkTree, addingTree);
}