#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

class BitcoinExchange {
private:
    std::map<std::string, float> priceData_;

    static bool parseDate(const std::string& dateStr);
    static bool parseValue(const std::string& valueStr, float& value, std::string& errorMsg);
    void loadDatabase(const std::string& filename);
    float findClosestPrice(const std::string& date);

	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
public:
    BitcoinExchange();
    ~BitcoinExchange();

    void processInputFile(const std::string& inputFile);
};

#endif
