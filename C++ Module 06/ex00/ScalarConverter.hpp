#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <string>
#include <limits>

#define NAN   (0.0 / 0.0)
#define INFINITY   (1.0 / 0.0)

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &src);
        ~ScalarConverter();

    public:
        static void convert(std::string const &literal);
};

enum Type
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
};

#endif
