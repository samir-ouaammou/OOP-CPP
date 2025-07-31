#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float const xVal, float const yVal) : _x(xVal), _y(yVal)
{
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point   &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return (_x);
}

Fixed Point::getY() const
{
    return (_y);
}
