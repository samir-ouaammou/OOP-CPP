#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

        void    parseDatabase(const std::string &fileName);
        void    parseInputFile(const std::string &fileName);
        void    handleLine(const std::string &line);
        bool    findValue(const std::string &date, float &rate) const;
        bool    isValidDate(const std::string &date) const;
        bool    isValidValue(const std::string &valueStr, float &value) const;
};

#endif
