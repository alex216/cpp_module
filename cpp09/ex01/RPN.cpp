#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token) {
    if (token.empty()) return false;
    
    size_t start = 0;
    if (token[0] == '-' || token[0] == '+') {
        if (token.length() == 1) return false;
        start = 1;
    }
    
    for (size_t i = start; i < token.length(); ++i) {
        if (!std::isdigit(token[i])) return false;
    }
    return true;
}

double RPN::performOperation(double a, double b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator");
}

double RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    
    while (iss >> token) {
        if (isNumber(token)) {
            const double num = std::atof(token.c_str());
            stack_.push(num);
        } else if (isOperator(token)) {
            if (stack_.size() < 2) {
                throw std::runtime_error("Error");
            }
            
            const double b = stack_.top(); stack_.pop();
            const double a = stack_.top(); stack_.pop();
            
            const double result = performOperation(a, b, token);
            stack_.push(result);
        } else {
            throw std::runtime_error("Error");
        }
    }
    
    if (stack_.size() != 1) {
        throw std::runtime_error("Error");
    }
    
    return stack_.top();
}