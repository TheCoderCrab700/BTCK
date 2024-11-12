#ifndef CONGTRINHKHOAHOC_H
#define CONGTRINHKHOAHOC_H

#include "date.h"
#include <string>

class CongTrinhKhoaHoc {
    std::string Ma;
    Date nsb;
    bool khuvuc; // true for international, false for domestic

public:

    CongTrinhKhoaHoc(const std::string& ma = "", const Date& publicationDate = Date(), bool isInternational = false)
        : Ma(ma), nsb(publicationDate), khuvuc(isInternational) {} 

    ~CongTrinhKhoaHoc();

    // Getters
    std::string getMa() const;
    Date getNsb() const;
    bool isInternational() const;

    // Setters
    void setMa(const std::string& ma);
    void setNsb(const Date& publicationDate);
    void setKhuVuc(bool isInternational);

    // Display function
    void displayInfo() const;

private:
    // Add any other private helper functions if necessary
};

#endif // CONGTRINHKHOAHOC_H
