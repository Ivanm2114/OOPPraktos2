#include <iostream>
#include <string>
#include "Tree.h"
#include <fstream>

using namespace std;

int main() {
    auto a1 = Date(1,1,20);
    auto b1 = Date(2,2,20);


    string s1 = "a";
    string s2 = "test.txt";
    auto Tr1 = Tree("Root",a1);
    Tr1.add("Root2", b1);
    Tr1.write2File(s2);

    return 0;
}
