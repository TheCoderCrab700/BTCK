#include <iostream>
#include "CongTrinhKhoaHoc.h"
#include "date.h"

int main() {
    try {
        // Test default constructor
        std::cout << "Testing default constructor:" << std::endl;
        CongTrinhKhoaHoc defaultCTKH;
        defaultCTKH.displayInfo();
        
        // Test parameterized constructor with valid data
        std::cout << "\nTesting parameterized constructor with valid data:" << std::endl;
        Date validDate(15, 10, 2020); // Valid date
        CongTrinhKhoaHoc validCTKH("CTKH001", validDate, true);
        validCTKH.displayInfo();

        // Test parameterized constructor with invalid date
        std::cout << "\nTesting parameterized constructor with invalid date:" << std::endl;
        Date invalidDate(31, 2, 2021); // Invalid date (Feb 31 doesn't exist)
        CongTrinhKhoaHoc invalidCTKH("CTKH002", invalidDate, false); // Should throw an exception
        invalidCTKH.displayInfo();
    } 
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        // Test setMa() with invalid data
        std::cout << "\nTesting setMa with empty identifier:" << std::endl;
        CongTrinhKhoaHoc testCTKH;
        testCTKH.setMa(""); // Should throw an exception
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        // Test setNsb() with invalid date
        std::cout << "\nTesting setNsb with invalid date:" << std::endl;
        CongTrinhKhoaHoc testCTKH;
        Date invalidDate(30, 2, 2020); // Invalid date
        testCTKH.setNsb(invalidDate); // Should throw an exception
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
