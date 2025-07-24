#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe    &PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::jacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);

    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

int PmergeMe::binarySearchVector(const std::vector<int> &sorted, int value, int high)
{
    int low = 0;
    while (low < high)
    {
        int mid = (low + high) / 2;

        if (value < sorted[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (low);
}

int PmergeMe::binarySearchDeque(const std::deque<int> &sorted, int value, int high)
{
    int low = 0;

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (value < sorted[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (low);
}

void    PmergeMe::fordJohnsonSortVector(std::vector<int> &vector)
{
    int n = (int)vector.size();
    if (n <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> remaining;

    int i = 0;
    for (; i + 1 < n; i += 2)
    {
        if (vector[i] < vector[i + 1])
            pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
        else
            pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
    }
    if (i < n)
        remaining.push_back(vector[i]);

    std::vector<int> largerElements;
    for (size_t j = 0; j < pairs.size(); ++j)
        largerElements.push_back(pairs[j].second);

    fordJohnsonSortVector(largerElements);

    std::vector<int> sorted;
    sorted.reserve(n);

    if (!pairs.empty())
        sorted.push_back(pairs[0].first);

    for (size_t j = 0; j < largerElements.size(); ++j)
        sorted.push_back(largerElements[j]);

    std::vector<int> smallerElements;
    for (size_t j = 1; j < pairs.size(); ++j)
        smallerElements.push_back(pairs[j].first);

    for (size_t j = 0; j < remaining.size(); ++j)
        smallerElements.push_back(remaining[j]);

    insertRemainingVector(sorted, smallerElements);

    vector = sorted;
}

void    PmergeMe::insertRemainingVector(std::vector<int> &sorted, const std::vector<int> &remaining)
{
    int size = (int)remaining.size();

    if (size == 0)
        return;

    int idx = 0;
    int jCount = 0;
    std::vector<int> order;

    while (jCount < size)
    {
        int jNum = jacobsthal(idx);
        if (jNum >= size)
            break;
        order.push_back(jNum);
        idx++;
        jCount++;
    }

    for (int i = (int)order.size() - 1; i >= 0; --i)
    {
        int pos = binarySearchVector(sorted, remaining[order[i]], (int)sorted.size());
        sorted.insert(sorted.begin() + pos, remaining[order[i]]);
    }

    for (int i = 0; i < size; ++i)
    {
        if (std::find(order.begin(), order.end(), i) == order.end())
        {
            int pos = binarySearchVector(sorted, remaining[i], (int)sorted.size());
            sorted.insert(sorted.begin() + pos, remaining[i]);
        }
    }
}

void    PmergeMe::fordJohnsonSortDeque(std::deque<int> &deque)
{
    int n = (int)deque.size();
    if (n <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> remaining;

    int i = 0;
    for (; i + 1 < n; i += 2)
    {
        if (deque[i] < deque[i + 1])
            pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
        else
            pairs.push_back(std::make_pair(deque[i + 1], deque[i]));
    }
    if (i < n)
        remaining.push_back(deque[i]);

    std::vector<int> largerElements;
    for (size_t j = 0; j < pairs.size(); ++j)
        largerElements.push_back(pairs[j].second);

    fordJohnsonSortVector(largerElements);

    std::deque<int> sorted;

    if (!pairs.empty())
        sorted.push_back(pairs[0].first);

    for (size_t j = 0; j < largerElements.size(); ++j)
        sorted.push_back(largerElements[j]);

    std::vector<int> smallerElements;
    for (size_t j = 1; j < pairs.size(); ++j)
        smallerElements.push_back(pairs[j].first);

    for (size_t j = 0; j < remaining.size(); ++j)
        smallerElements.push_back(remaining[j]);

    insertRemainingDeque(sorted, smallerElements);

    deque = sorted;
}

void    PmergeMe::insertRemainingDeque(std::deque<int> &sorted, const std::vector<int> &remaining)
{
    int size = (int)remaining.size();
    if (size == 0)
        return;

    int idx = 0;
    int jCount = 0;
    std::vector<int> order;

    while (jCount < size)
    {
        int jNum = jacobsthal(idx);
        if (jNum >= size)
            break;
        order.push_back(jNum);
        idx++;
        jCount++;
    }

    for (int i = (int)order.size() - 1; i >= 0; --i)
    {
        int pos = binarySearchDeque(sorted, remaining[order[i]], (int)sorted.size());
        sorted.insert(sorted.begin() + pos, remaining[order[i]]);
    }

    for (int i = 0; i < size; ++i)
    {
        if (std::find(order.begin(), order.end(), i) == order.end())
        {
            int pos = binarySearchDeque(sorted, remaining[i], (int)sorted.size());
            sorted.insert(sorted.begin() + pos, remaining[i]);
        }
    }
}

long long   PmergeMe::getTimeMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000000 + tv.tv_usec;
}

void    PmergeMe::addToContainers(const std::string &input)
{
    std::istringstream iss(input);
    std::string temp;
    
    while (iss >> temp)
    {
        long long   num = 0;
    
        for (size_t i = 0; i < temp.size(); i++)
        {
            if (temp[i] < '0' || temp[i] > '9' || num > 2147483647)
            {
                std::cerr << "Error: Invalid input: " << temp << std::endl;
                exit(1);
            }
            num = num * 10 + (temp[i] - '0');
        }
        bool isValideNum = (std::find(_vector.begin(), _vector.end(), num) != _vector.end());
        if (isValideNum)
        {
            std::cerr << "Error: Duplicate number found: " << num << std::endl;
            exit(1);
        }
        _vector.push_back(num);
        _deque.push_back(num);
    }
}

void    PmergeMe::sortVector()
{
    long long start = getTimeMicroseconds();
    fordJohnsonSortVector(_vector);
    long long end = getTimeMicroseconds();
    _vectorTime = end - start;
}

void    PmergeMe::sortDeque()
{
    long long start = getTimeMicroseconds();
    fordJohnsonSortDeque(_deque);
    long long end = getTimeMicroseconds();
    _dequeTime = end - start;
}

void    PmergeMe::printVectorBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void    PmergeMe::printDequeBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _deque.size(); ++i)
        std::cout << _deque[i] << " ";
    std::cout << std::endl;
}

void    PmergeMe::printVectorAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void    PmergeMe::printDequeAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < _deque.size(); ++i)
        std::cout << _deque[i] << " ";
    std::cout << std::endl;
}

void    PmergeMe::printTiming() const
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << static_cast<double>(_vectorTime) << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << static_cast<double>(_dequeTime) << " us" << std::endl;
}
