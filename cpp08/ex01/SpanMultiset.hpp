#ifndef SPANMULTISET_HPP
#define SPANMULTISET_HPP

#include <set>          // multiset

class SpanMultiset
{
private:
	unsigned int capacity_;
	std::multiset<int> database_;

	SpanMultiset();
public:
	SpanMultiset(unsigned int n);
	SpanMultiset(const SpanMultiset &src);
	SpanMultiset &operator=(const SpanMultiset &src);
	~SpanMultiset(void);

	void addNumber(int num);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
};
#endif
