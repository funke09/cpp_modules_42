#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

BitcoinExchange::BitcoinExchange()
{
    std::srand(std::time(0));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
        *this = rhs;
    }
    return *this;
}

void BitcoinExchange::parsefile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if(!file)
    {
        throw std::runtime_error("Could not open file");
        return;
    }
    BitcoinExchange::ExchangeRates rates;
    std::ifstream input("data.csv");
    if(!input)
    {
        throw std::runtime_error("Could not open file");
        return;
    }
    std::string line;
    while(std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string date_str;
        double rate;
        if(std::getline(ss, date_str, ',') && ss >> rate)
        {
            rates[date_str] = rate;
        }
    }
    input.close();
    

}