#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    _vectorTime = 0;
    _dequeTime = 0;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        _vector = src._vector;
        _deque = src._deque;
        _vectorTime = src._vectorTime;
        _dequeTime = src._dequeTime;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

long long   PmergeMe::getTime()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (static_cast<long long>(time.tv_sec) * 1000000 + time.tv_usec);
}

void    PmergeMe::addToVector(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        std::stringstream ss(token);
        long    num;

        ss >> num;
        if (ss.fail() || !ss.eof() || num < 0 || num > 2147483647)
        {
            std::cerr << "Error" << std::endl;
            exit (1);
        }
        _vector.push_back(num);
    }
}

void    PmergeMe::addToDeque(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        std::stringstream ss(token);
        long    num;

        ss >> num;
        if (ss.fail() || !ss.eof() || num < 0 || num > 2147483647)
        {
            std::cerr << "Error" << std::endl;
            exit (1);
        }
        _deque.push_back(num);
    }
}

void    PmergeMe::printVectorBefore() const
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::printDequeBefore() const
{
    std::cout << "Before: ";
    for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::printVectorAfter() const
{
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::printDequeAfter() const
{
    std::cout << "After: ";
    for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    PmergeMe::printTiming() const
{
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}

void    PmergeMe::mergeInsertSortVector(std::vector<int> &vector)
{
    if (vector.size() <= 1)
        return;

    std::vector<int>    left(vector.begin(), vector.begin() + vector.size() / 2);
    std::vector<int>    right(vector.begin() + vector.size() / 2, vector.end());

    mergeInsertSortVector(left);
    mergeInsertSortVector(right);

    vector.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(vector));
}

void    PmergeMe::mergeInsertSortDeque(std::deque<int> &deque)
{
    if (deque.size() <= 1)
        return;

    std::deque<int> left(deque.begin(), deque.begin() + deque.size() / 2);
    std::deque<int> right(deque.begin() + deque.size() / 2, deque.end());

    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);

    deque.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(deque));
}

void    PmergeMe::insertInSortedVector(std::vector<int> &vector, int value)
{
    vector.insert(std::upper_bound(vector.begin(), vector.end(), value), value);
}

void    PmergeMe::insertInSortedDeque(std::deque<int> &deque, int value)
{
    deque.insert(std::upper_bound(deque.begin(), deque.end(), value), value);
}

void    PmergeMe::sortVector()
{
    long long start = getTime();
    mergeInsertSortVector(_vector);
    long long end = getTime();
    _vectorTime = end - start;
}

void    PmergeMe::sortDeque()
{
    long long start = getTime();
    mergeInsertSortDeque(_deque);
    long long end = getTime();
    _dequeTime = end - start;
}
