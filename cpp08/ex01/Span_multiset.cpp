#include "Span_multiset.hpp"

Span_multiset::Span_multiset(unsigned int n) : capacity_(n)
{
}

Span_multiset::Span_multiset(const Span_multiset &src)
{
	*this = src;
}

Span_multiset &Span_multiset::operator=(const Span_multiset &src)
{
	if (this != &src)
	{
		this->capacity_ = src.capacity_;
		this->database_ = src.database_;
	}
	return *this;
}

Span_multiset::~Span_multiset(void)
{
}

void Span_multiset::addNumber(int num)
{
	if (database_.size() >= capacity_)
	{
		throw std::length_error("Span is full");
	}
	database_.insert(num);
}

unsigned int Span_multiset::shortestSpan(void) const
{
	if (database_.size() < 2)
	{
		throw std::logic_error("Not enough numbers");
	}

	unsigned int min_span = UINT_MAX;
	std::multiset<int>::const_iterator it = database_.begin();
	std::multiset<int>::const_iterator next_it = it;
	++next_it;

	while (next_it != database_.end())
	{
		const unsigned int span = *next_it - *it;
		if (span < min_span)
		{
			min_span = span;
		}
		++it;
		++next_it;
	}
	return min_span;
}

unsigned int Span_multiset::longestSpan() const
{
	if (database_.size() < 2)
	{
		throw std::logic_error("Not enough numbers");
	}

	return static_cast<unsigned int>(*database_.rbegin() - *database_.begin());
}