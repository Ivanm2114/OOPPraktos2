#include <iostream>
#include <string>
#include "Tree.h"
#include <fstream>
#include <assert.h>

using namespace std;

int main() {
    auto a1 = Date(10, 1, 2023);
    auto b1 = Date(2, 2, 2024);
    auto c1 = Date(2, 4, 2023);
    auto d1 = Date(3,4,2025);


    string s1 = "a";
    string s2 = "test.txt";
    Tree Tr3 = Tree<string,Date>();
    assert(Tr3.getCounter()==0);
    Tree Tr1 = Tree("Root"s, a1);
    assert(Tr1.getCounter()==1);
    Tr1.add("Root2"s, b1);
    assert(Tr1.getCounter()==2);
    Tr1.add("Root3"s, c1);
    assert(Tr1.getCounter()==3);
    Tr1.add("Root3"s, c1);
    assert(Tr1.getCounter()==3);
    Tree Tr2 = Tree(Tr1);
    auto Tr5 = *(Tr1&&Tr2);
    assert(Tr2.getCounter()==3);
    assert((Tr2==Tr1)==true);
    assert((Tr5==Tr1) == true);
    assert((Tr5==Tr2) == true);
    Tr2.deleteAll();
    assert(Tr2.getCounter()==0);
    assert((Tr2 == Tr3)==true);
    auto Tr4 = Tr1&&Tr3;
    assert(Tr4->getCounter()==0);
    Tr1.write2File(s2);
    Tr2.getFromFile(s2);
    assert((Tr2==Tr1)==true);
    Tr2.deleteValue("Root"s);
    assert((Tr2==Tr1)==false);
    auto Tr6 = Tree(Tr1);
    assert((Tr6==Tr1)== true);
    Tr6.add("Root5",d1);
    assert((Tr6==Tr1)==false);



    return 0;
}
