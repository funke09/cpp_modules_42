#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

typedef std::map<std::string, double> ExchangeRates;

bool isValidDate(const std::string& date) {
    // Check if date is in the format "YYYY-MM-DD"
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    // Check if year, month and day are valid integers
    int year, month, day;
    std::stringstream ss(date);
    char dash;
    ss >> year >> dash >> month >> dash >> day;
    if (ss.fail() || ss.get() != EOF) {
        return false;
    }
    // Check if month and day are within valid ranges
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    return true;
}

bool isValidValue(const std::string& value) {
    // Check if value is a valid float or positive integer between 0 and 1000
    double val;
    std::stringstream ss(value);
    ss >> val;
    if (ss.fail() || ss.get() != EOF) {
        return false;
    }
    if (val < 0 || val > 1000) {
        return false;
    }
    return true;
}

bool readExchangeRates(const std::string& filename, ExchangeRates& rates) {
    std::ifstream file(filename.c_str());
    if (!file) {
        throw std::runtime_error("Could not open file");
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date_str;
        double rate;
        if (std::getline(ss, date_str, ',') && ss >> rate) {
            rates[date_str] = rate;
        }
    }
    file.close();
    return true;
}

double getExchangeRate(const std::string& date, const ExchangeRates& rates) {
    ExchangeRates::const_iterator it = rates.find(date);
    if (it != rates.end()) {
        return it->second;
    }
    ExchangeRates::const_iterator lower = rates.lower_bound(date);
    if (lower == rates.begin()) {
        return 0.0;
    }
    ExchangeRates::const_iterator upper = lower;
    --lower;
    double rate1 = lower->second;
    double rate2 = upper->second;
    std::string date1 = lower->first;
    std::string date2 = upper->first;
    double diff_days = std::floor((std::atof(date.c_str()) - std::atof(date1.c_str())) / (std::atof(date2.c_str()) - std::atof(date1.c_str())) * 365.25);
    return rate1 + (rate2 - rate1) / (std::atof(date2.c_str()) - std::atof(date1.c_str())) * diff_days;
}

int main(int argc, char **argv) 
{
    if (argc < 2) {
        std::cout << "Usage: ./program input.txt" << std::endl;
        return 1;
    }
    std::string input_filename = argv[1];
    std::ifstream input_file(input_filename.c_str());
    if (!input_file) 
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    ExchangeRates rates;
    if (!readExchangeRates("data.csv", rates)) 
    {
        std::cout << "Error: could not open data file." << std::endl;
        return 1;
    }
    std::cout << "Rates:" << rates[0] << std::endl;
    std::string line;
    while (std::getline(input_file, line)) 
    {
        std::stringstream ss(line);
        std::string date_str, value_str;
        char delim;
        double value;
        if (std::getline(ss, date_str, '|') && ss >> value >> delim) 
        {
            if (!isValidDate(date_str)) 
            {
                std::cout << "Error: bad date format => " << date_str << std::endl;
                continue;
            }
            if (!isValidValue(std::to_string(value))) 
            {
            std::cout << "Error: not a valid value => " << value << std::endl;
            continue;
            }
            double exchange_rate = getExchangeRate(date_str, rates);
            if (exchange_rate == 0.0) 
            {
            std::cout << "Error: no exchange rate found for date " << date_str << std::endl;
            continue;
            }
            std::cout << date_str << " => " << value << " = " << value * exchange_rate << std::endl;
        }
        else 
        {
        std::cout << line << std::endl;
        }
    }
    input_file.close();
return 0;
}