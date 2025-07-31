#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

class Span
{
    private:
        unsigned int        _maxSize;
        std::vector<int>    _data;

    public:
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &src);
        ~Span();

        void    addNumber(int nbr);
        int     shortestSpan(void) const;
        int     longestSpan(void) const;

        template <typename InputIterator>
        void    addRange(InputIterator begin, InputIterator end)
        {
            size_t  rangeSize = std::distance(begin, end);
        
            if (_data.size() + rangeSize > _maxSize)
                throw std::out_of_range("addRange: Span will exceed max capacity");

            _data.insert(_data.end(), begin, end);
        }
};

#endif
