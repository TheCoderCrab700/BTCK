#include "Sach.h"
#include "date.h"
#include <iostream>

int main() {
    try {
        // Test parameterized constructor with valid data
        std::cout << "\nTesting parameterized constructor with valid data:" << std::endl;
        Date validDate(10, 5, 2022); // Valid date
        Sach validBook("SACH001", validDate, true, "Science Fiction");
        validBook.displayInfo();

        // Test parameterized constructor with empty 'loai' field
        std::cout << "\nTesting parameterized constructor with empty 'loai' field:" << std::endl;
        Sach emptyLoaiBook("SACH002", validDate, false, ""); // Should be valid
        emptyLoaiBook.displayInfo();

        // Test setloai with invalid data (empty loai)
        std::cout << "\nTesting setloai with empty 'loai' value:" << std::endl;
        emptyLoaiBook.setloai(""); // Should throw an exception

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
