#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <vector>
#include <cstdlib>
#include <climits>
#include <iomanip>

std::vector<int>    insertOrder(int n)
{
    std::vector<int>    jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    int prev = 1;
    int next = 3;
    while (static_cast<int>(jacob.size()) < n)
    {
        for (int i = (next >= n ? n - 1 : next); i > prev; --i)
        {
            jacob.push_back(i);
            if (static_cast<int>(jacob.size()) == n)
                break;
        }
        prev = next;
        next = next + 2 * prev;
    }
    return (jacob);
}

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
        std::vector<int>    indeces = insertOrder(smls.size());
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

void    printVectorBefore(const std::vector<int> &vector)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << " ";
    std::cout << std::endl;
}

void    printVectorAfter(const std::vector<int> &vector)
{
    std::cout << "After:  ";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << " ";
    std::cout << std::endl;
}

long long   getTimeMicroseconds()
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    return (long long)(time.tv_sec) * 1000000 + time.tv_usec;
}

void    printTiming(long long start, long long end, size_t size)
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << size << "  elements with std::vector : " << static_cast<double>(end - start) << " us" << std::endl;
}

std::vector<int>    parseInput(int &ac, char **av)
{
    std::vector<int>    result;
    for (int i = 1; i < ac; ++i)
    {
        char    *end;
        long    num = std::strtol(av[i], &end, 10);
        if (*end != '\0' || num < 0 || num > INT_MAX)
            throw std::runtime_error("Error: Invalid input -> " + static_cast<std::string>(av[i]));

        bool isDuplicate = (std::find(result.begin(), result.end(), num) != result.end());
        if (isDuplicate)
            throw std::runtime_error("Error: Duplicate number found: " + static_cast<std::string>(av[i]));

        result.push_back(static_cast<int>(num));
    }
    return (result);
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <numbers...>" << std::endl;
        return (1);
    }

    try
    {
        std::vector<int>    input;
        long long   timeStart;
        long long   timeEnd;

        input = parseInput(ac, av);
        printVectorBefore(input);
        timeStart = getTimeMicroseconds();
        sortVector(input);
        timeEnd = getTimeMicroseconds();
        printVectorAfter(input);
        printTiming(timeStart, timeEnd, input.size());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
