#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange();

    BitcoinExchange &operator=(const BitcoinExchange &rhs);

    void parsefile(const std::string &filename);

    private:
    typedef std::map<std::string, double> ExchangeRates;
};

#endif