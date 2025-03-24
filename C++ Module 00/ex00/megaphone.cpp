#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    short   i;
    short   j;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (-1);
    }

    i = 0;
    while (++i < ac)
    {
        if (i != 1)
            std::cout << " ";

        j = -1;
        while (av[i][++j])
            std::cout << (char)std::toupper(av[i][j]);
    }
    std::cout << std::endl;
    
    return (0);
}
