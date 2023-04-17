#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream> 
#include <fstream>
#include <sstream> 
#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string& File);
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& obj);

		float getExchangeRate(const std::string& date, float value) const;

	private:
		bool	isValidDate(const std::string& date) const;

		std::map<std::string, float> ExchangeRates;
		class RuntimeError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: could not open database file.");
				}
		};

		class InvalidArgument : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: no exchange rate found for given date.");
				}
		};

		class NegativeValue : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: not a positive number.");
				}
		};

		class TooLargeNumber : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: too large a number.");
				}
		};

		class InvalidDate : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: invalid date.");
				}
		};
};


#endif