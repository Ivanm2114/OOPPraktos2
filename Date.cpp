#include "Date.h"


Date::Date(){
    day=month=year=0;
}

bool Date::canSetDate(int day, int month, int year) const {
    if((month==1 or month == 3 or month == 5 or
        month == 7 or month == 8 or month == 10 or
        month == 12) and day<=31)
        return true;
    if((month==4 or month==6 or month==9 or month==11) and day<=30) return true;
    if(month==2 and day<=28) return true;
    return false;

}

void Date::setDate(const int day, const int month, const int year) {
    if(canSetDate(day,month,year)){
        this->day=day;
        this->month=month;
        this->year=year;
    }
}




Date::Date(const int day, const int month, const int year) {
    this->day=this->month=this->year=0;
    setDate(day,month,year);
}

Date::Date(const Date &originDate) {
    this->day=originDate.day;
    this->month=originDate.month;
    this->year=originDate.year;
}

bool Date::operator<(const Date &obj) const {
    if(this->year<obj.year) return true;
    if(this->year==obj.year and this->month<obj.month) return true;
    if(this->year==obj.year and this->month==obj.month and this->day<obj.day) return true;
    return false;
}