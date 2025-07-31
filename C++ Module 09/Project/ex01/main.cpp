#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: invalid arguments" << std::endl;
        return 1;
    }

    std::string input = av[1];

    checkInput(input);
    calculatrice(input);

    return 0;
}
