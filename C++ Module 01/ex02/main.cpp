#include <iostream>

int	main(void)
{
	std::string MyString = "HI THIS IS BRAIN";
	std::string *stringPTR = &MyString;
	std::string &stringREF = MyString;

	std::cout << "Memory address of myString:   " << &MyString << std::endl;
    std::cout << "Memory address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Memory address held by REF:   " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of myString:            " << MyString << std::endl;
    std::cout << "Value pointed to by PTR:      " << *stringPTR << std::endl;
    std::cout << "Value pointed to by REF:      " << stringREF << std::endl;

	return (0);
}
