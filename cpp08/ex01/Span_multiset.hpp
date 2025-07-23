#ifndef SPAN_MULTISET_HPP
#define SPAN_MULTISET_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span_multiset
{
private:
	unsigned int capacity_;
	std::multiset<int> database_;

	Span_multiset();
public:
	Span_multiset(unsigned int n);
	Span_multiset(const Span_multiset &src);
	Span_multiset &operator=(const Span_multiset &src);
	~Span_multiset(void);

	void addNumber(int num);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
};
#endif