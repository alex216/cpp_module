#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>
#include <climits>

// altered_jacobsthal 0,1,1,3,5,11,...
std::vector<size_t> PmergeMe::genAlterJacobsthalSeq(size_t n) {
    std::vector<size_t> altered_jacobsthal;
    altered_jacobsthal.push_back(0);
    altered_jacobsthal.push_back(1);
    
    size_t next = 1;
    while (next < n) {
        next = altered_jacobsthal[altered_jacobsthal.size() - 1] + 2 * altered_jacobsthal[altered_jacobsthal.size() - 2];
        altered_jacobsthal.push_back(next);
    }
    return altered_jacobsthal;
}


bool PmergeMe::parseArguments(int argc, char** argv, std::vector<int>& numbers) {
    numbers.clear();
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg.empty()) {
            return false;
        }
        
        // if (arg[0] == '-') {
        //     return false;
        // }
        
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                return false;
            }
        }
        
        std::istringstream iss(arg);
        long num;
        iss >> num;
        
        if (num > INT_MAX || num < 0) {
            return false;
        }
        
        numbers.push_back(static_cast<int>(num));
    }
    
    return !numbers.empty();
}

void PmergeMe::printSequence(const std::vector<int>& arr, const std::string& label) {
    std::cout << label;
    for (size_t i = 0; i < arr.size() && i < 30; ++i) {
        std::cout << " " << arr[i];
    }
    if (arr.size() > 30) {
        std::cout << " [...]";
    }
    std::cout << std::endl;
}
