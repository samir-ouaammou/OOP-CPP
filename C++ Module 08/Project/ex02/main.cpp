#include "MutantStack.hpp"
#include <iostream>
#include <string>

int main()
{
    MutantStack<std::string> s;
    s.push("one");
    s.push("two");
    s.push("three");

    std::cout << "Normal iteration:\n";
    for (MutantStack<std::string>::iterator it = s.begin(); it != s.end(); ++it)
        std::cout << *it << "\n";

    std::cout << "\nReverse iteration:\n";
    for (MutantStack<std::string>::reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
        std::cout << *it << "\n";

    const MutantStack<std::string> cs = s;
    std::cout << "\nConst iteration:\n";
    for (MutantStack<std::string>::const_iterator it = cs.begin(); it != cs.end(); ++it)
        std::cout << *it << "\n";

    return 0;
}
