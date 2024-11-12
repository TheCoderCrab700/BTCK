#include "CongTrinhKhoaHoc.h"
#include <iostream>
#include <stdexcept>  // For standard exceptions


// Destructor
CongTrinhKhoaHoc::~CongTrinhKhoaHoc() {}

// Getter for Ma
std::string CongTrinhKhoaHoc::getMa() const {
    return Ma;
}

// Getter for nsb (publication date)
Date CongTrinhKhoaHoc::getNsb() const {
    return nsb;
}

// Getter for khuvuc (isInternational)
bool CongTrinhKhoaHoc::isInternational() const {
    return khuvuc;
}

// Setter for Ma
void CongTrinhKhoaHoc::setMa(const std::string& ma) {
    if (ma.empty()) {
        throw std::invalid_argument("Error: 'Ma' cannot be empty.");
    }
    Ma = ma;
}

// Setter for nsb (publication date)
void CongTrinhKhoaHoc::setNsb(const Date& publicationDate) {
    if (!publicationDate.isvalid()) {  // Assuming Date class has an isvalid() method
        throw std::invalid_argument("Error: Invalid publication date.");
    }
    nsb = publicationDate;
}

// Setter for khuvuc (isInternational)
void CongTrinhKhoaHoc::setKhuVuc(bool isInternational) {
    khuvuc = isInternational;
}

// Display information
void CongTrinhKhoaHoc::displayInfo() const {
    try {
        std::cout << "Ma: " << Ma << std::endl;
        std::cout << "Publication Date: ";
        std::cout<<nsb; // Assuming Date class has a display() method
        std::cout << "Location: " << (khuvuc ? "International" : "Domestic") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error displaying information: " << e.what() << std::endl;
    }
}
