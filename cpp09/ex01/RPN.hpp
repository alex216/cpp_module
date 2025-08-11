#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib> 

class RPN {
private:
    std::stack<double> stack_;

    static bool isOperator(const std::string& token);
    static bool isNumber(const std::string& token);
    static double performOperation(double a, double b, const std::string& op);

public:
    RPN();
    ~RPN();
    double evaluate(const std::string& expression);
};

#endif
