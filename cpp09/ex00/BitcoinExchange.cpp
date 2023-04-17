#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string& File)
{
	std::ifstream file(File.c_str());
	if (!file.is_open())
		throw RuntimeError();
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		float value;
		if (std::getline(ss, date, ',') && ss >> value)
			ExchangeRates[date] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& object)
{
	*this = object;
	return ;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& object)
{
	if (this != &object)
		this->ExchangeRates = object.ExchangeRates;
	return (*this);
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	int year, month, day;
	char separator;
	std::istringstream ss(date);
	ss >> year >> separator >> month >> separator >> day;
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
	}
	else if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	return (true);
}

float BitcoinExchange::getExchangeRate(const std::string& date, float value) const
{
	if (value < 0)
		throw NegativeValue();
	if (value > 1000)
		throw TooLargeNumber();
	if (isValidDate(date) == false)
		throw InvalidDate();
	std::map<std::string, float>::const_iterator it = ExchangeRates.find(date);
	if (it == ExchangeRates.end())
	{
		it = ExchangeRates.upper_bound(date);
		if (it == ExchangeRates.begin())
			throw InvalidArgument();
		--it;
	}
	return (it->second);
}
