#include "iter.hpp"

int main()
{
    int arrInt[5] = {1, 2, 3, 4, 5};
    std::string arrStr[3] = {"Samir", "Ouaammou", "1337"};

    std::cout << "Int array:" << std::endl;
    iter(arrInt, 5, printElement);

    std::cout << "String array:" << std::endl;
    iter(arrStr, 3, printElement);

    return (0);
}
