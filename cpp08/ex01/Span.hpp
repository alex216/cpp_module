#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
private:
	unsigned int capacity_;
	mutable std::vector<int> database_;

	Span();
public:
	Span(unsigned int n);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span(void);

	void addNumber(int num);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
};
#endif
