#include "PmergeMe.hpp"

void    sortVector(std::vector<int> &input)
{
    if (input.size() <= 1)
        return;

    std::vector<int>    bigs;
    std::vector<int>    smls;

    for (size_t i = 0; i < input.size() - 1; i += 2)
    {
        if (input[i] > input[i + 1])
        {
            bigs.push_back(input[i]);
            smls.push_back(input[i + 1]);
        }
        else
        {
            bigs.push_back(input[i + 1]);
            smls.push_back(input[i]);
        }
    }

    int leftover = (input.size() % 2 != 0) ? input.back() : -1;

    sortVector(bigs);

    std::vector<int>    sorted = bigs;

    if (!smls.empty())
    {
        std::vector<int>    indeces = insertOrder<std::vector<int> >(smls.size());
        for (size_t i = 0; i < smls.size(); ++i)
        {
            int idx = indeces[i];
            std::vector<int>::iterator  pos = std::lower_bound(sorted.begin(), sorted.end(), smls[idx]);
            sorted.insert(pos, smls[idx]);
        }
    }

    if (leftover != -1)
    {
        std::vector<int>::iterator  pos = std::lower_bound(sorted.begin(), sorted.end(), leftover);
        sorted.insert(pos, leftover);
    }

    input = sorted;
}

void    sortDeque(std::deque<int> &input)
{
    if (input.size() <= 1)
        return;

    std::deque<int>    bigs;
    std::deque<int>    smls;

    for (size_t i = 0; i < input.size() - 1; i += 2)
    {
        if (input[i] > input[i + 1])
        {
            bigs.push_back(input[i]);
            smls.push_back(input[i + 1]);
        }
        else
        {
            bigs.push_back(input[i + 1]);
            smls.push_back(input[i]);
        }
    }

    int leftover = (input.size() % 2 != 0) ? input.back() : -1;

    sortDeque(bigs);

    std::deque<int>    sorted = bigs;

    if (!smls.empty())
    {
        std::deque<int>    indeces = insertOrder<std::deque<int> >(smls.size());
        for (size_t i = 0; i < smls.size(); ++i)
        {
            int idx = indeces[i];
            std::deque<int>::iterator  pos = std::lower_bound(sorted.begin(), sorted.end(), smls[idx]);
            sorted.insert(pos, smls[idx]);
        }
    }

    if (leftover != -1)
    {
        std::deque<int>::iterator  pos = std::lower_bound(sorted.begin(), sorted.end(), leftover);
        sorted.insert(pos, leftover);
    }

    input = sorted;
}


long long   getTimeMicroseconds()
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    return (long long)(time.tv_sec) * 1000000 + time.tv_usec;
}

void    printTiming(long long start, long long end, size_t size, std::string name)
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << size << "  elements with std::" << name << " : " << static_cast<double>(end - start) << " us" << std::endl;
}

void    parseInput(int &ac, char **av, std::vector<int> &vector, std::deque<int> &deque)
{
    std::vector<int>    vec;
    std::deque<int>     deq;
    for (int i = 1; i < ac; ++i)
    {
        char    *end;
        long    num = std::strtol(av[i], &end, 10);
        if (*end != '\0' || num < 0 || num > INT_MAX)
            throw std::runtime_error("Error: Invalid input -> " + static_cast<std::string>(av[i]));

        bool isDuplicate = (std::find(vec.begin(), vec.end(), num) != vec.end());
        if (isDuplicate)
            throw std::runtime_error("Error: Duplicate number found: " + static_cast<std::string>(av[i]));

        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
    vector = vec;
    deque = deq;
}
