#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Samir", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // غادي تولي 1
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // خاص ترجع Exception
    }
    catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "-------------" << std::endl;

    try {
        Bureaucrat b2("Karim", 151); // خطأ فـ constructor
    }
    catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
