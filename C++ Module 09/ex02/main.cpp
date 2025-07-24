#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Please provide numbers as arguments." << std::endl;
        return (1);
    }

    std::string input;
    for (int i = 1; i < ac; ++i)
        input += av[i] + std::string(" ");

    PmergeMe sorter;

    sorter.addToContainers(input);

    sorter.printVectorBefore();

    sorter.sortVector();
    sorter.sortDeque();

    sorter.printVectorAfter();

    sorter.printTiming();

    return (0);
}
