#include "PmergeMe.hpp"

bool    isPositiveInteger(const std::string &input)
{
    if (input.empty())
        return (false);

    for (size_t i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
            return (false);
    }

    std::stringstream ss(input);
    long num;

    ss >> num;
    if (ss.fail() || !ss.eof() || num < 0 || num > 2147483647)
        return (false);

    return (true);
}


int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cerr << "Error: no input provided" << std::endl;
        return (1);
    }

    PmergeMe sorter;

    for (int i = 1; i < ac; ++i)
    {
        std::string arg(av[i]);
        if (!isPositiveInteger(arg))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        sorter.addToVector(arg);
        sorter.addToDeque(arg);
    }

    sorter.printVectorBefore();
    // sorter.printDequeBefore();

    sorter.sortVector();
    sorter.sortDeque();

    sorter.printVectorAfter();
    // sorter.printDequeAfter();
    sorter.printTiming();

    return (0);
}
