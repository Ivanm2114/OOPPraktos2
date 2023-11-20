#include <iostream>
#include <string.h>

using namespace std;


class Date{
public:
    Date();
    Date(const int day,const int month, const int year);
    Date(Date const &date);
    void setDate(const int day,const int month, const int year);

private:
int year;
int month;
int day;

};

class StudentLeaf{
public:
    StudentLeaf();
    StudentLeaf(string name, Date date);
    StudentLeaf(StudentLeaf const &leaf);
    void setName(string name);
    void setDate(Date date);
    void setNameAndDate(string name, Date date);
    bool canSetName(string name) const;
    void canSetDate(Date date) const;
private:
    string studentName;
    Date lessonDate;
    StudentLeaf &leftStudent;
    StudentLeaf &rightStudent;
    StudentLeaf &parentLeaf;
};


class StudentTree{
public:
    StudentTree();
    StudentTree(StudentLeaf const &baseLeaf);
    StudentTree(StudentTree const &baseLeaf);
    void add(StudentLeaf leaf);


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
