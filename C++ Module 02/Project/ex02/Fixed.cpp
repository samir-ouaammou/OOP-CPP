#include "Fixed.hpp"

const int    Fixed::_fractionalBits = 8;

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

std::ostream    &operator<<(std::ostream &cout, const Fixed &fixed)
{
    cout << fixed.toFloat();
    return (cout);
}

bool    Fixed::operator>(const Fixed &other) const
{
    return (this->toFloat() > other.toFloat());
}

bool    Fixed::operator<(const Fixed &other) const
{
    return (this->toFloat() < other.toFloat());
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return (this->toFloat() >= other.toFloat());
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return (this->toFloat() <= other.toFloat());
}

bool    Fixed::operator==(const Fixed &other) const
{
    return (this->toFloat() == other.toFloat());
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    if (other.toFloat() == 0)
    {
        std::cout << "Error: division by zero is undefined" << std::endl;
        exit (-1) ;
    }
    return (this->toFloat() / other.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
    Fixed   tmp = *this;

    ++this->_value;
    return (tmp);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed   tmp = *this;
    
	--this->_value;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);

	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);

	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);

	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);

	return (b);
}
