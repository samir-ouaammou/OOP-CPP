#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point();
        Point(float const x, float const y);
        Point(const Point &other);
        Point& operator=(const Point &other);
        ~Point();

        Fixed   getX() const;
        Fixed   getY() const;
};

#endif
