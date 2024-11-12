#include "Sach.h"
#include <iostream>
#include <stdexcept> // For exception handling

// Parameterized constructor
Sach::Sach(const std::string& ma, const Date& publicationDate, bool isInternational, 
               const std::string& cate)
    : CongTrinhKhoaHoc(ma, publicationDate, isInternational), loai(cate) {
    if (cate.empty()) {
        throw std::invalid_argument("Error: Tên CTKH không thể trống");
    }
}

// Destructor
Sach::~Sach() {}

// Getter for journal cate
std::string Sach::getloai() const {
    return loai;
}


// Setter for journal cate
void Sach::setloai(const std::string& journal) {
    if (journal.empty()) {
        throw std::invalid_argument("Error: 'loai' cannot be empty.");
    }
    loai = journal;
}

// Display information
void Sach::displayInfo() const {
    CongTrinhKhoaHoc::displayInfo(); // Display base class info
    std::cout << "Thể loại bài báo: " << loai << std::endl;
}
