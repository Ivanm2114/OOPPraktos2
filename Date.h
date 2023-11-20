#ifndef OOP_LABA4_DATE_H
#define OOP_LABA4_DATE_H

#endif //OOP_LABA4_DATE_H

class Date{
public:
    Date();
    Date(const int day,const int month, const int year);
    Date(Date const &originDate);
    bool operator < (const Date &obj) const;
    void setDate(const int day,const int month, const int year);
    bool canSetDate(int day, int month,  int year) const;


private:
    int year;
    int month;
    int day;

};