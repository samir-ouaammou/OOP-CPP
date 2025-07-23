#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>
#include <sys/time.h>

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

        void    addToVector(const std::string &input);
        void    addToDeque(const std::string &input);

        void    printVectorBefore() const;
        void    printDequeBefore() const;
        void    printVectorAfter() const;
        void    printDequeAfter() const;
        void    printTiming() const;

        void    sortVector();
        void    sortDeque();

        void    mergeInsertSortVector(std::vector<int> &vector);
        void    mergeInsertSortDeque(std::deque<int> &deque);

        void    insertInSortedVector(std::vector<int> &vector, int value);
        void    insertInSortedDeque(std::deque<int> &deque, int value);

        long long   getTime();
};

#endif
