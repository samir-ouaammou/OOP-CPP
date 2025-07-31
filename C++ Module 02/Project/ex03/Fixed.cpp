#include "Fixed.hpp"

Fixed::Fixed()
{
    _value = 0;
}

Fixed::Fixed(const int nbr)
{
    _value = nbr << _fractionalBits;
}

Fixed::Fixed(const float nbr)
{
    _value = static_cast<int>(roundf(nbr * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    _value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{

    if (this != &other)
        _value = other.getRawBits();

    return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

int Fixed::toInt(void) const
{
    return (_value >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_value) / (1 << _fractionalBits));
}

std::ostream    &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}
