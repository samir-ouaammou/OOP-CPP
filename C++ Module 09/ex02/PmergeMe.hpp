#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>
#include <stdexcept>

class PmergeMe
{
    private:
        std::vector<int>    _vector;
        std::deque<int>     _deque;

        long long   _vectorTime;
        long long   _dequeTime;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        
        void    printVectorBefore() const;
        void    printDequeBefore() const;
        void    printVectorAfter() const;
        void    printDequeAfter() const;
        void    printTiming() const;

        void    addToContainers(const std::string& input);
        
        void    sortVector();
        void    sortDeque();

        int     jacobsthal(int n);
        
        void    fordJohnsonSortVector(std::vector<int> &vector);
        void    fordJohnsonSortDeque(std::deque<int> &deque);

        int     binarySearchVector(const std::vector<int> &sorted, int value, int high);
        int     binarySearchDeque(const std::deque<int> &sorted, int value, int high);

        void    insertRemainingVector(std::vector<int> &sorted, const std::vector<int> &remaining);
        void    insertRemainingDeque(std::deque<int> &sorted, const std::vector<int> &remaining);

        long long getTimeMicroseconds();


};

#endif
