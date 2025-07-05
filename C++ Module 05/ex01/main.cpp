#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("Youssef", 50);
        Form f("FormA", 40, 30);

        std::cout << b << std::endl;
        std::cout << f << std::endl;

        b.signForm(f);

        Bureaucrat b2("Khadija", 30);
        b2.signForm(f);

        std::cout << f << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
