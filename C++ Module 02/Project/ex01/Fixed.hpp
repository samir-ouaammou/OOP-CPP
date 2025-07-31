# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int    _fractionalBits = 8;

    public:
        Fixed ();
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed (const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed ();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;
};

std::ostream    &operator<<(std::ostream &cout, const Fixed &fixed);

#endif
