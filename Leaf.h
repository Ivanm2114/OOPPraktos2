
#ifndef OOP_LABA4_STUDENTLEAF_H
#define OOP_LABA4_STUDENTLEAF_H

#endif //OOP_LABA4_STUDENTLEAF_H

#include <string>
#include "Date.h"
#include <iostream>
#include <fstream>


using namespace std;

template<class V, class K>
class Leaf {
public:
    Leaf();

    Leaf(V data, K date);

    Leaf(Leaf const &leaf);

    ~Leaf();

    void setDataAndDate(V data, K date);

    bool canSetData(V data) const;

    bool operator==(Leaf<V, K> &obj) const;

    bool canSetLeaf(const Leaf<V, K> *leaf) const;

    void setRightLeaf(Leaf<V, K> *leaf);

    void setLeftLeaf(Leaf<V, K> *leaf);

    void setParentLeaf(Leaf<V, K> *leaf);

    string print(char c) const;

    string write2File() const;

    bool empty() const;

    K getDate() const;

    Leaf<V, K> *getLeftLeaf() const;

    Leaf<V, K> *getRightLeaf() const;

    void dropParentLeaf();

    Leaf<V, K> *searchValue(V name);

    V getData() const;



private:
    V data;
    K date;
    Leaf<V, K> *leftLeaf = nullptr;
    Leaf<V, K> *rightLeaf = nullptr;
    Leaf<V, K> *parentLeaf = nullptr;

};

template<class V, class K>
Leaf<V, K>::Leaf() {}


using namespace std;

template<class V, class K>
Leaf<V, K>::Leaf(V data, K date) {
    this->data = data;
    this->date = K(date);
    leftLeaf = nullptr;
    rightLeaf = nullptr;
    parentLeaf = nullptr;
}

template<class V, class K>
Leaf<V, K>::Leaf(const Leaf<V, K> &leaf) {
    leftLeaf = nullptr;
    rightLeaf = nullptr;
    parentLeaf = nullptr;
    this->data = leaf.data;
    this->date = K(leaf.date);
}

template<class V, class K>
bool Leaf<V, K>::canSetData(V data) const {
    return data == NULL;
}

template<class V, class K>
void Leaf<V, K>::setDataAndDate(V data, K date) {
    if (canSetName(data)) {
        this->data = data;
        date = T2(date);
    }
}

template<class V, class K>
bool Leaf<V, K>::operator==(Leaf<V, K> &obj) const {
    bool flag = (this->data == obj.data) and (this->date == obj.date);
    if (rightLeaf != nullptr and obj.getRightLeaf() != nullptr) {
        flag *= *(rightLeaf) == *(obj.getRightLeaf());
    }
    if (leftLeaf != nullptr and obj.getLeftLeaf() != nullptr) {
        flag *= *(leftLeaf) == *(obj.getLeftLeaf());
    }
    if ((leftLeaf != nullptr and obj.getLeftLeaf() == nullptr) or
        (rightLeaf != nullptr and obj.getRightLeaf() == nullptr))
        flag *= false;
    return flag;
}


template<class V, class K>
bool Leaf<V, K>::canSetLeaf(const Leaf<V, K> *leaf) const {
    return leaf != nullptr;
}

template<class V, class K>
void Leaf<V, K>::setRightLeaf(Leaf<V, K> *leaf) {
    if (canSetLeaf(leaf))
        rightLeaf = leaf;
}

template<class V, class K>
void Leaf<V, K>::setLeftLeaf(Leaf<V, K> *leaf) {
    if (canSetLeaf(leaf))
        leftLeaf = leaf;
}

template<class V, class K>
void Leaf<V, K>::setParentLeaf(Leaf<V, K> *leaf) {
    if (canSetLeaf(leaf))
        parentLeaf = leaf;
}

template<class V, class K>
bool Leaf<V, K>::empty() const {
    return date.isnull();
}

template<class V, class K>
K Leaf<V, K>::getDate() const {
    return date;
}


template<class V, class K>
V Leaf<V, K>::getData() const {
    return data;
}

template<class V, class K>
Leaf<V, K> *Leaf<V, K>::getLeftLeaf() const {
    return leftLeaf;
}

template<class V, class K>
Leaf<V, K> *Leaf<V, K>::getRightLeaf() const {
    return rightLeaf;
}

template<class V, class K>
void Leaf<V, K>::dropParentLeaf() {
    if (parentLeaf->rightLeaf == this) { parentLeaf->rightLeaf = nullptr; }
    else { parentLeaf->leftLeaf = nullptr; }
    parentLeaf= nullptr;
}

template<class V, class K>
Leaf<V, K>::~Leaf() {
    if (rightLeaf != nullptr) delete rightLeaf;
    if (leftLeaf != nullptr) delete leftLeaf;
}


template<class V, class K>
Leaf<V, K> *Leaf<V, K>::searchValue(V name) {
    if (data == name) { return this; }
    else {
        Leaf<V, K> *t = nullptr;
        if (leftLeaf != nullptr)
            t = leftLeaf->searchValue(name);
        if (t == nullptr and rightLeaf != nullptr)
            t = rightLeaf->searchValue(name);
        return t;
    }
}


template<class V, class K>
string Leaf<V, K>::print(char c) const {
    string temp;
    if (leftLeaf != nullptr) {
        temp += getLeftLeaf()->print(c);
    }
    temp += data;
    temp += " ";
    temp += date.print();
    temp += c;
    if (rightLeaf != nullptr){ temp += getRightLeaf()->print(c);}
    return temp;

}

template<class V,class K>
string Leaf<V,K>::write2File() const {
    string temp;
    temp += data;
    temp += " ";
    temp += date.print();
    temp += "\n";
    if (leftLeaf != nullptr) {
        temp += getLeftLeaf()->write2File();
    }
    if (rightLeaf != nullptr){ temp += getRightLeaf()->write2File();}
    return temp;
}