# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _value;
        static const int    _fractionalBits = 8;

    public:
        Fixed ();
        Fixed (const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed ();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
