#include "iter.hpp"

int main()
{
    int arrInt[5] = {1, 2, 3, 4, 5};
    std::string arrStr[3] = {"cpp", "module", "07"};

    std::cout << "Int array:" << std::endl;
    iter(arrInt, 5, printElement);

    std::cout << "String array:" << std::endl;
    iter(arrStr, 3, printElement);

    double arrDouble[4] = {1.1, 2.2, 3.3, 4.4};
    std::cout << "Double array:" << std::endl;
    iter(arrDouble, 4, printElement);

    return 0;
}
