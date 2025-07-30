#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
        return (1);
    }

    try
    {
        std::vector<int>    vector;
        std::deque<int>     deque;
        long long   timeStart;
        long long   timeEnd;

        parseInput(ac, av, vector, deque);
        
        //----------< vector >----------
        printContainers(vector, "Before");
        timeStart = getTimeMicroseconds();
        sortVector(vector);
        timeEnd = getTimeMicroseconds();
        printContainers(vector, "After");
        printTiming(timeStart, timeEnd, vector.size(), "vector");
        
        //----------< deque >----------
        timeStart = getTimeMicroseconds();
        sortDeque(deque);
        timeEnd = getTimeMicroseconds();
        printTiming(timeStart, timeEnd, deque.size(), "deque ");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
