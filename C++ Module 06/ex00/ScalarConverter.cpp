#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

Type    detectType(const std::string &str)
{
    if (str.empty())
        return (TYPE_INVALID);

    if (str.size() == 1 && !std::isdigit(str[0]))
        return (TYPE_CHAR);

    if (str == "nanf" || str == "+inff" || str == "-inff")
        return (TYPE_FLOAT);

    if (str == "nan" || str == "+inf" || str == "-inf")
        return (TYPE_DOUBLE);

    std::istringstream iss(str);
    int i;
    
    iss >> std::noskipws >> i;
    if (iss.eof() && !iss.fail())
        return (TYPE_INT);

    if (str.size() > 1 && str[str.size() - 1] == 'f')
    {
        std::string sub = str.substr(0, str.size() - 1);
        std::istringstream issf(sub);
        float f;
        issf >> std::noskipws >> f;
        if (issf.eof() && !issf.fail())
            return (TYPE_FLOAT);
    }
    std::istringstream issd(str);
    double d;
    issd >> std::noskipws >> d;
    if (issd.eof() && !issd.fail())
        return (TYPE_DOUBLE);
        
    return (TYPE_INVALID);
}

bool    isDisplayable(char c)
{
    return (c >= 32 && c <= 126);
}

void    ScalarConverter::convert(const std::string &literal)
{
    const std::string   &str = literal;
    Type    type = detectType(str);

    std::cout << std::fixed << std::setprecision(1);

    if (type == TYPE_CHAR)
    {
        char    c = str[0];
        std::cout << "char:   '" << c << "'" << std::endl;
        std::cout << "int:    " << static_cast<int>(c) << std::endl;
        std::cout << "float:  " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return ;
    }

    if (type == TYPE_INT)
    {
        long    l;
        std::istringstream iss(str);

        iss >> l;
        if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
        {
            std::cout << "char:   impossible\nint:    impossible\nfloat:  impossible\ndouble: impossible" << std::endl;
            return ;
        }

        int     i = static_cast<int>(l);
        char    c = static_cast<char>(i);

        if (isDisplayable(c))
            std::cout << "char:   '" << c << "'" << std::endl;
        else if (i >= 0 && i <= 127)
            std::cout << "char:   Non displayable" << std::endl;
        else
            std::cout << "char:   impossible" << std::endl;

        if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
            std::cout << "int:    impossible" << std::endl;
        else
            std::cout << "int:    " << i << std::endl;
    
        std::cout << "float:  " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
        return ;
    }

    if (type == TYPE_FLOAT)
    {
        float   f;
        if (str == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (str == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (str == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else
        {
            std::string sub = str.substr(0, str.size() - 1);
            std::istringstream iss(sub);
            iss >> f;
        }
        if (f != f || f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity())
            std::cout << "char:   impossible\nint:    impossible" << std::endl;
        else
        {
            char c = static_cast<char>(f);
            int i = static_cast<int>(f);

            if (isDisplayable(c))
                std::cout << "char:   '" << c << "'" << std::endl;
            else if (i >= 0 && i <= 127)
                std::cout << "char:   Non displayable" << std::endl;
            else
                std::cout << "char:   impossible" << std::endl;

            std::cout << "int:    " << i << std::endl;
        }
        
        std::cout << "float:  " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return ;
    }

    if (type == TYPE_DOUBLE)
    {
        double  d;
        if (str == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (str == "+inf")
            d = std::numeric_limits<double>::infinity();
        else if (str == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else
        {
            std::istringstream iss(str);
            iss >> d;
        }

        if (d != d || d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity())
            std::cout << "char:   impossible\nint:    impossible" << std::endl;
        else
        {
            char c = static_cast<char>(d);
            int i = static_cast<int>(d);
            if (isDisplayable(c))
                std::cout << "char:   '" << c << "'" << std::endl;
            else if (i >= 0 && i <= 127)
                std::cout << "char:   Non displayable" << std::endl;
            else
                std::cout << "char:   impossible" << std::endl;
            
            if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
                std::cout << "int:    impossible" << std::endl;
            else
                std::cout << "int:    " << i << std::endl;
        }

        std::cout << "float:  " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return ;
    }
    std::cout << "char:   impossible\nint:    impossible\nfloat:  impossible\ndouble: impossible" << std::endl;
}
