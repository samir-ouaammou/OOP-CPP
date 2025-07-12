#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void    printElement(const T &elem)
{
    std::cout << elem << std::endl;
}

template <typename T>
void    iter(T *array, size_t length, void (*func)(T const &))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
