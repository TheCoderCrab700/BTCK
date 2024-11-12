#include "Baibao.h"
#include "date.h"
#include <iostream>

int main() {
    try {
        Date publicationDate(15, 10, 2021);  // Assuming this date is valid

        Baibao paper("BB001", publicationDate, true, "Journal of Science", 12);
        paper.displayInfo();

        // Testing invalid input for journal name
        Baibao invalidPaper("BB002", publicationDate, false, "", 10);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
