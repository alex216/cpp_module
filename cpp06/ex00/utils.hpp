#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstring>
#include <stdexcept>
#include <limits>
#include <cerrno>
#include <cstdlib>

bool is_printable(const char c);
int my_stoi(const char *str);
float my_stof(const char *str);
double my_stod(const char *str);

#endif
