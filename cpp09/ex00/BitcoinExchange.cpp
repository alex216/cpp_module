#include "BitcoinExchange.hpp"

#include <string>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::parseDate(const std::string& dateStr) {
    if (dateStr.length() != 10) return false;
    if (dateStr[4] != '-' || dateStr[7] != '-') return false;
    
    const std::string year = dateStr.substr(0, 4);
    const std::string month = dateStr.substr(5, 2);
    const std::string day = dateStr.substr(8, 2);
    
    for (size_t i = 0; i < year.length(); ++i) if (!std::isdigit(year[i])) return false;
    for (size_t i = 0; i < month.length(); ++i) if (!std::isdigit(month[i])) return false;
    for (size_t i = 0; i < day.length(); ++i) if (!std::isdigit(day[i])) return false;
    
    const int y = std::atoi(year.c_str());
    const int m = std::atoi(month.c_str());
    const int d = std::atoi(day.c_str());

    if (y < 1900 || y > 3000) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;

    const int original_year = y;
    const int original_month = m;
    const int original_day = d;
    
    struct tm timeinfo = {
        .tm_mday = d,
        .tm_mon = m - 1,
        .tm_year = y - 1900,
    };

    if (std::mktime(&timeinfo) == -1) return false;

    return (timeinfo.tm_year + 1900 == original_year &&
            timeinfo.tm_mon + 1 == original_month &&
            timeinfo.tm_mday == original_day);
}

bool BitcoinExchange::parseValue(const std::string& valueStr, float& value, std::string& errorMsg) {
    try {
        value = std::atof(valueStr.c_str());
        if (value < 0) {
            errorMsg = "Error: not a positive number.";
            return false;
        }
        if (value > 1000) {
            errorMsg = "Error: too large a number.";
            return false;
        }
        return true;
    } catch (...) {
        errorMsg = "Error: bad input => " + valueStr;
        return false;
    }
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
		exit(1);
    }
    
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, rate_str;
        
        if (std::getline(iss, date, ',') && std::getline(iss, rate_str)) {
            const float rate = std::atof(rate_str.c_str());
            priceData_[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::findClosestPrice(const std::string& date) {
    std::map<std::string, float>::iterator it = priceData_.upper_bound(date);
    if (it == priceData_.begin()) {
        return priceData_.begin()->second;
    }
    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) {
    loadDatabase("data.csv");
    
    std::ifstream file(inputFile.c_str());
    std::string line;
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    bool first_line = true;
    while (std::getline(file, line)) {
        if (first_line) {
            first_line = false;
            continue;
        }
        
        const size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pipe_pos);
        std::string value_str = line.substr(pipe_pos + 1);
        
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        value_str.erase(0, value_str.find_first_not_of(" \t"));
        value_str.erase(value_str.find_last_not_of(" \t") + 1);
        
        if (!parseDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        float value;
        std::string err_msg;
        if (!parseValue(value_str, value, err_msg)) {
            std::cerr << err_msg << std::endl;
            continue;
        }
        
        const float btc_price = findClosestPrice(date);
        const float result = value * btc_price;
        
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}
