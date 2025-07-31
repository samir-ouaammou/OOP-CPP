#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    try
    {
        Span sp(10);
        std::vector<int> moreNumbers;

        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(9);

        moreNumbers.push_back(1);
        moreNumbers.push_back(7);
        moreNumbers.push_back(10);
        moreNumbers.push_back(2);

        sp.addRange(moreNumbers.begin(), moreNumbers.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        sp.addNumber(6);
        sp.addNumber(8);
        sp.addNumber(15);

        sp.addNumber(42);

    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
