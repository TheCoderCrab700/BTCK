#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    // Constructors
    Date(int d = 1, int m = 1, int y = 0);
    Date(const Date& other);

    // Member functions
    void set_to(int d = 0, int m = 0, int y = 0);
    bool isleap() const;
    int lastday() const;

    // Operator Overloading
    Date operator+(int num) const;
    Date operator-(int num) const;
    Date operator++();
    Date operator--();
    Date operator++(int);
    Date operator--(int);
    Date& operator=(const Date& other);
    Date& operator+=(int num);
    Date& operator-=(int num);

    // I/O Operator Overloading
    friend istream& operator>>(istream& in, Date& date);
    friend ostream& operator<<(ostream& out, const Date& date);
};

#endif // DATE_H
