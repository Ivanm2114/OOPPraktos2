#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

int main() {
    auto a1 = Date(1,1,20);
    auto b1 = Date(2,2,20);
    auto a2 = Date(1,1,20);
    auto b2 = Date(2,2,20);
    string s1 = "a";
    string s2 = "b";
    auto Tr1 = Tree('a',a1);
    Tr1.add('a',b1);
    auto Tr2 = Tree('a',a2);
    Tr2.add('a',b2);
    cout << bool(Tr1==Tr2);
    cout <<Tr1.getCounter();
    Tr1.deleteAll();
    cout << Tr1.getCounter();

    return 0;
}
