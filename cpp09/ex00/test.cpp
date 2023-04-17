// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <map>
// #include <cmath>
// typedef std::map<std::string, double> ExchangeRates;

// bool isValidDate(const std::string& date) {
//     // Check if date is in the format "YYYY-MM-DD"
//     if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
//         return false;
//     }
//     // Check if year, month and day are valid integers
//     int year, month, day;
//     std::stringstream ss(date);
//     char dash;
//     ss >> year >> dash >> month >> dash >> day;
//     if (ss.fail() || ss.get() != EOF) {
//         return false;
//     }
//     // Check if month and day are within valid ranges
//     if (month < 1 || month > 12 || day < 1 || day > 31) {
//         return false;
//     }
//     return true;
// }

// bool isValidValue(const std::string& value) {
//     // Check if value is a valid float or positive integer between 0 and 1000
//     double val;
//     std::stringstream ss(value);
//     ss >> val;
//     if (ss.fail() || ss.get() != EOF) {
//         return false;
//     }
//     if (val < 0 || val > 1000) {
//         return false;
//     }
//     return true;
// }

// bool readExchangeRates(const std::string& filename, ExchangeRates& rates) {
//     std::ifstream file(filename.c_str());
//     if (!file) {
//         return false;
//     }
//     std::string line;
//     while (std::getline(file, line)) {
//         std::stringstream ss(line);
//         std::string date_str;
//         double rate;
//         if (std::getline(ss, date_str, ',') && ss >> rate) {
//             rates[date_str] = rate;
//         }
//     }
//     file.close();
//     return true;
// }


// double getExchangeRate(const std::string& date, const ExchangeRates& rates) {
//     ExchangeRates::const_iterator it = rates.find(date);
//     if (it != rates.end()) {
//         return it->second;
//     }
//     ExchangeRates::const_iterator lower = rates.lower_bound(date);
//     if (lower == rates.begin()) {
//         return 0.0;
//     }
//     ExchangeRates::const_iterator upper = lower;
//     --lower;
//     double rate1 = lower->second;
//     double rate2 = upper->second;
//     std::string date1 = lower->first;
//     std::string date2 = upper->first;
//     double diff_days = std::floor((std::atof(date.c_str()) - std::atof(date1.c_str())) / (std::atof(date2.c_str()) - std::atof(date1.c_str())) * 365.25);
//     return rate1 + (rate2 - rate1) / (std::atof(date2.c_str()) - std::atof(date1.c_str())) * diff_days;
// }


// int main(int ac, char **av) {
//     ExchangeRates rates;
//     if(ac != 2)
//     {
//         std::cout << "Error: Invalid number of arguments." << std::endl;
//         return 1;
//     }
//     if (!readExchangeRates(av[1], rates)) {
//         std::cout << "Error: Could not read exchange rates from file." << std::endl;
//         return 1;
//     }
//     std::string date, from_currency, to_currency, value_str;
//     std::cout << "Enter date in the format 'YYYY-MM-DD': ";
//     std::getline(std::cin, date);
//     if (!isValidDate(date)) {
//         std::cout << "Error: Invalid date format." << std::endl;
//         return 1;
//     }
//     // std::cout << "Enter currency to convert from: ";
//     // std::getline(std::cin, from_currency);
//     // std::cout << "Enter currency to convert to: ";
//     // std::getline(std::cin, to_currency);
//     // std::cout << "Enter value to convert: ";
//     std::getline(std::cin, value_str);
//     if (!isValidValue(value_str)) {
//         std::cout << "Error: Invalid value." << std::endl;
//         return 1;
//     }
//     double rate_from = getExchangeRate(date, rates);
//     double rate_to = getExchangeRate(date, rates);
//     double value = std::atof(value_str.c_str());
//     double converted_value = value * rate_from / rate_to;
//     std::cout << value_str << " " << from_currency << " is equivalent to " << converted_value << " " << to_currency << "." << std::endl;
//     return 0;
// }


#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& databaseFile);
    BitcoinExchange(const BitcoinExchange& obj);
    ~BitcoinExchange();

    BitcoinExchange& operator=(const BitcoinExchange& obj);

    float getExchangeRate(const std::string& date, float value) const;

    friend std::ostream& operator<<(std::ostream& o, const BitcoinExchange& i);

private:
    bool isValidDate(const std::string& dateStr) const;

    std::map<std::string, float> exchangeRates;

    class runtimeError : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: could not open bitcoin price database file.";
        }
    };

    class invalidArgument : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: no exchange rate found for given date.";
        }
    };

    class negativeValue : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: not a positive number.";
        }
    };

    class tooLargeNumber : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: too large a number.";
        }
    };

    class inexistentDate : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: inexistent date.";
        }
    };
};

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    // load exchange rates from database file
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
    // copy exchange rates from obj
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
    if (this != &obj) {
        // copy exchange rates from obj
    }
    return *this;
}

float BitcoinExchange::getExchangeRate(const std::string& date, float value) const {
    if (!isValidDate(date)) {
        throw inexistentDate();
    }
    if (value <= 0) {
        throw negativeValue();
    }
    if (value > 1000000) {
        throw tooLargeNumber();
    }
    std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
    if (it == exchangeRates.end()) {
        throw invalidArgument();
    }
    return it->second * value;
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) const {
    // check if date is valid
    return true;
}

std::ostream& operator<<(std::ostream& o, const BitcoinExchange& i) {
    // print exchange rates to o
    return o;
}

int main() {
    try {
        BitcoinExchange exchange;
        std::cout << exchange.getExchangeRate("2022-01-01", 1000) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
