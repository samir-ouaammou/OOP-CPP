#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(3.0f, 3.0f);
    Point outside(10.0f, 10.0f);
    Point onEdge(5.0f, 0.0f);
    Point onCorner(0.0f, 0.0f);

    std::cout << "Point inside:   " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point outside:  " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point on edge:  " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
    std::cout << "Point on corner:" << (bsp(a, b, c, onCorner) ? "true" : "false") << std::endl;

    return 0;
}
