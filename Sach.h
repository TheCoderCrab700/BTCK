#ifndef SACH_H
#define SACH_H

#include "CongTrinhKhoaHoc.h"
#include <string>

class Sach : public CongTrinhKhoaHoc {
    std::string loai;

public:
    // Constructors and Destructor
    Sach(const std::string& ma = "", const Date& publicationDate = Date(), bool isInternational = 0, 
           const std::string& cate = "");
    ~Sach();

    // Getters
    std::string getloai() const;

    // Setters
    void setloai(const std::string& journal);

    // Display function
    void displayInfo() const;
};

#endif // SACH_H
