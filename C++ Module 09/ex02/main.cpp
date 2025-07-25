#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <vector>
#include <cstdlib>
#include <climits>
#include <iomanip>

std::vector<int>    parseInput(int ac, char **av)
{
    std::vector<int> result;
    for (int i = 1; i < ac; ++i)
    {
        char *end;
        long num = std::strtol(av[i], &end, 10);
        if (*end != '\0' || num > INT_MAX || num < INT_MIN)
        {
            std::cerr << "Error: Invalid input -> " << av[i] << std::endl;
            std::exit(1);
        }
        bool isDuplicate = (std::find(result.begin(), result.end(), num) != result.end());
        if (isDuplicate)
        {
            std::cerr << "Error: Duplicate number found: " << num << std::endl;
            exit(1);
        }
        result.push_back(static_cast<int>(num));
    }
    return (result);
}

void    pairAndCompare(const std::vector<int> &input, std::vector<int> &bigs, std::vector<int> &smalls, int &leftover)
{
    leftover = -1;
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            bigs.push_back(input[i]);
            smalls.push_back(input[i + 1]);
        }
        else
        {
            bigs.push_back(input[i + 1]);
            smalls.push_back(input[i]);
        }
    }
    if (input.size() % 2 != 0)
        leftover = input.back();
}

size_t  binarySearchPosition(const std::vector<int> &vector, int value, size_t limit)
{
    size_t low = 0;
    size_t high = limit;

    while (low < high)
    {
        size_t mid = (low + high) / 2;
        if (vector[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return (low);
}

std::vector<int>    generateJacobsthal(int n)
{
    std::vector<int> seq;

    if (n >= 0)
        seq.push_back(0);
    if (n >= 1)
        seq.push_back(1);

    while (true)
    {
        int next = seq.back() + 2 * seq[seq.size() - 2];
        if (next > n)
            break;
        seq.push_back(next);
    }
    return (seq);
}

std::vector<size_t> prepareInsertionOrder(size_t n)
{
    std::vector<size_t> order;
    if (n == 0)
        return order;

    std::vector<int> jacob = generateJacobsthal(n);
    order.push_back(0);

    for (size_t g = 2; g < jacob.size(); ++g)
    {
        size_t start = jacob[g - 1];
        size_t end = jacob[g];
        for (size_t j = end; j > start; --j)
        {
            if (j - 1 < n)
                order.push_back(j - 1);
        }
    }

    size_t last = jacob.empty() ? 1 : jacob.back();
    while (last < n)
    {
        order.push_back(last);
        last++;
    }

    return (order);
}

void    insertFirstSmall(std::vector<int> &S, const std::vector<int> &smalls)
{
    if (!smalls.empty())
    {
        size_t pos = binarySearchPosition(S, smalls[0], S.size());
        S.insert(S.begin() + pos, smalls[0]);
    }
}

void    analyzePairing(const std::vector<int> &smalls, std::vector<int> &remaining, int leftover)
{
    for (size_t i = 1; i < smalls.size(); ++i)
        remaining.push_back(smalls[i]);
    if (leftover != -1)
        remaining.push_back(leftover);
}

std::vector<int>    mergeInsertionSort(std::vector<int> input)
{
    if (input.size() <= 1)
        return input;

    std::vector<int> bigs, smalls;
    int leftover;
    pairAndCompare(input, bigs, smalls, leftover);

    std::vector<int> S = mergeInsertionSort(bigs);
    insertFirstSmall(S, smalls);

    std::vector<int> remaining;
    analyzePairing(smalls, remaining, leftover);

    std::vector<size_t> order = prepareInsertionOrder(remaining.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        if (order[i] >= remaining.size())
            continue;

        int val = remaining[order[i]];
        size_t pos = binarySearchPosition(S, val, S.size());
        S.insert(S.begin() + pos, val);
    }

    return (S);
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
    std::cout << "After: ";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << " ";
    std::cout << std::endl;
}

long long   getTimeMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000000 + tv.tv_usec;
}

void    printTiming(long long start, long long end, size_t size)
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << size << "  elements with std::vector : " << static_cast<double>(end - start) << " us" << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: " << av[0] << " <numbers...>" << std::endl;
        return 1;
    }

    long long start;
    long long end;
    std::vector<int> input;
    std::vector<int> sorted;

    input = parseInput(ac, av);
    printVectorBefore(input);
    start = getTimeMicroseconds();
    sorted = mergeInsertionSort(input);
    end = getTimeMicroseconds();
    printVectorAfter(sorted);
    printTiming(start, end, input.size());

    return (0);
}
