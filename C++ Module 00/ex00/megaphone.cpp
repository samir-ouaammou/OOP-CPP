#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (-1);
    }

    for (short i = 1; i < ac; i++)
    {
        if (i != 1)
            std::cout << " ";

        for (short j = 0; av[i][j]; j++)
            std::cout << (char)std::toupper(av[i][j]);
    }
    std::cout << std::endl;

    return (0);
}
