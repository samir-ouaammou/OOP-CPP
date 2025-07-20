#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
        this->_database = src._database;

    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void    BitcoinExchange::parseDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return ;
    }

    std::string line;
    float       value;

    std::getline(file, line); 

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
            continue;

        value = std::atof(valueStr.c_str());
        _database[date] = value;
    }
}

void    BitcoinExchange::parseInputFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
        handleLine(line);
}

void    BitcoinExchange::handleLine(const std::string &line)
{
    size_t sep = line.find(" | ");
    if (sep == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }

    std::string date = line.substr(0, sep);
    std::string valueStr = line.substr(sep + 3);

    float value;
    if (!isValidDate(date) || !isValidValue(valueStr, value))
        return;

    float rate;
    if (!findValue(date, rate))
        return;

    std::cout << date << " => " << value << " = " << rate * value << std::endl;
}

bool    BitcoinExchange::findValue(const std::string &date, float &rate) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    if (it != _database.end() && it->first == date)
    {
        rate = it->second;
        return (true);
    }

    if (it == _database.begin())
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return (false);
    }

    --it;
    rate = it->second;
    return (true);
}

bool    BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return (false);
    }

    return (true);
}

bool    BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const
{
    std::istringstream ss(valueStr);
    ss >> value;

    if (ss.fail() || !ss.eof())
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return (false);
    }

    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }

    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (false);
    }

    return (true);
}
