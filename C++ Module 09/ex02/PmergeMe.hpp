#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <vector>
#include <deque>

template<typename T>
void    printContainers(const T &container, std::string str)
{
    std::cout << str << ": ";
    for (size_t i = 0; i < container.size(); i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}

template<typename T>
T   insertOrder(int n)
{
    T   jacob;
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

#endif
