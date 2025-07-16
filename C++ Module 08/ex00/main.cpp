#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::cout << "<----------Testing easyfind with std::vector<int>---------->\n" << std::endl;
    std::vector<int>    Vector;

    Vector.push_back(1);
    Vector.push_back(2);
    Vector.push_back(3);
    Vector.push_back(4);
    Vector.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(Vector, 3);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(Vector, 6);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n<----------Testing easyfind with std::list<int>---------->\n" << std::endl;

    std::list<int>    List;

    List.push_back(10);
    List.push_back(20);
    List.push_back(30);
    List.push_back(40);
    List.push_back(50);

    try
    {
        std::list<int>::iterator it = easyfind(List, 30);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(List, 6);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
