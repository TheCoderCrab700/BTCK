#ifndef BAIBAO_H
#define BAIBAO_H

#include "CongTrinhKhoaHoc.h"
#include <string>

class Baibao : public CongTrinhKhoaHoc {
    std::string tenCTKH;
    int sotacgia;

public:
    // Constructors and Destructor
    Baibao(const std::string& ma = "", const Date& publicationDate = Date(), bool isInternational = 0, 
           const std::string& name = "", int Authornum = 0);
    ~Baibao();

    // Getters
    std::string gettenCTKH() const;
    int getsotacgia() const;

    // Setters
    void settenCTKH(const std::string& journal);
    void setsotacgia(int vol);


    // Display function
    void displayInfo() const;
};

#endif // BAIBAO_H
