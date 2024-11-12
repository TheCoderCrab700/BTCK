#include "Baibao.h"
#include <iostream>
#include <stdexcept> // For exception handling

// Parameterized constructor
Baibao::Baibao(const std::string& ma, const Date& publicationDate, bool isInternational, 
               const std::string& name, int num)
    : CongTrinhKhoaHoc(ma, publicationDate, isInternational), tenCTKH(name), sotacgia(num) {
    if (name.empty()) {
        throw std::invalid_argument("Error: Tên CTKH không thể trống");
    }
    if (num <= 0) {
        throw std::invalid_argument("Error:  Số tác giả phải lớn hơn 0");
    }
}

// Destructor
Baibao::~Baibao() {}

// Getter for journal name
std::string Baibao::gettenCTKH() const {
    return tenCTKH;
}

// Getter for sotacgia
int Baibao::getsotacgia() const {
    return sotacgia;
}

// Setter for journal name
void Baibao::settenCTKH(const std::string& journal) {
    if (journal.empty()) {
        throw std::invalid_argument("Error: 'tenCTKH' cannot be empty.");
    }
    tenCTKH = journal;
}

// Setter for sotacgia
void Baibao::setsotacgia(int num) {
    if (num <= 0) {
        throw std::invalid_argument("Error: 'sotacgia' must be greater than zero.");
    }
    sotacgia = num;
}

// Display information
void Baibao::displayInfo() const {
    CongTrinhKhoaHoc::displayInfo(); // Display base class info
    std::cout << "Tên bài báo: " << tenCTKH << std::endl;
    std::cout << "Số tác giả: " << sotacgia << std::endl;
}
