#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

void err(const std::string &msg);
std::string truncate(std::string);
std::string question(std::string question);
__attribute__((destructor)) void end();

#endif
