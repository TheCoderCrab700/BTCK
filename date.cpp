#include "Date.h"

// Constructor with default arguments
Date::Date(int d, int m, int y) {
    set_to(d, m, y);
}

// Copy constructor
Date::Date(const Date& other) {
    set_to(other.day, other.month, other.year);
}

// Set the date with validation
void Date::set_to(int d, int m, int y) {
    if (m < 1 || m > 12) {
        throw invalid_argument("Invalid month. Must be between 1 and 12.");
    }
    year = y;
    month = m;
    if (d < 1 || d > lastday()) {
        throw invalid_argument("Invalid day for the given month/year.");
    }
    day = d;
}

// Check if the year is a leap year
bool Date::isleap() const {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return (year % 4 == 0);
}

// Get the last day of the current month
int Date::lastday() const {
    int lsday[] = { 0, 31, isleap() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return lsday[month];
}

// Overload "+" operator
Date Date::operator+(int num) const {
    Date result(day, month, year);
    result += num;
    return result;
}

// Overload "-" operator
Date Date::operator-(int num) const {
    Date result(day, month, year);
    result -= num;
    return result;
}

// Prefix increment
Date Date::operator++() {
    *this += 1;
    return *this;
}

// Prefix decrement
Date Date::operator--() {
    *this -= 1;
    return *this;
}

// Postfix increment
Date Date::operator++(int) {
    Date tmp(day, month, year);
    *this += 1;
    return tmp;
}

// Postfix decrement
Date Date::operator--(int) {
    Date tmp(day, month, year);
    *this -= 1;
    return tmp;
}

// Overload "=" operator
Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

// Overload "+=" operator
Date& Date::operator+=(int num) {
    while (num > 0) {
        int tmp = lastday();
        if (day + num > tmp) {
            num -= (tmp - day + 1);
            day = 1;
            month++;
        } else {
            day += num;
            num = 0;
        }
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

// Overload "-=" operator
Date& Date::operator-=(int num) {
    while (num > 0) {
        if (day - num < 1) {
            num -= day;
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = lastday();
        } else {
            day -= num;
            num = 0;
        }
    }
    return *this;
}

// Input operator overloading
istream& operator>>(istream& in, Date& date) {
    string time;
    in >> time;
    int pre = time.find('/'), post = time.rfind('/');
    if (pre == string::npos || post == string::npos || pre == post) {
        throw invalid_argument("Invalid date format. Use DD/MM/YYYY.");
    }
    int d = stoi(time.substr(0, pre));
    int m = stoi(time.substr(pre + 1, post - pre - 1));
    int y = stoi(time.substr(post + 1));
    date.set_to(d, m, y);
    return in;
}

// Output operator overloading
ostream& operator<<(ostream& out, const Date& date) {
    if (date.day < 10) out << '0';
    out << date.day << '/';
    if (date.month < 10) out << '0';
    out << date.month << '/';
    out << setw(4) << setfill('0') << date.year;
    return out;
}
