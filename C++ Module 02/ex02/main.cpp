# include "Fixed.hpp"
#include <iostream>

int main( void )
{
    Fixed a(10) ,b(88);
    ;
    std::cout << Fixed::min(a, b) << std::endl;

    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}