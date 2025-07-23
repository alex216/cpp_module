#include "Span.hpp"

Span::Span(unsigned int n) : capacity_(n)
{
	database_.reserve(n);
}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->capacity_ = src.capacity_;
		this->database_ = src.database_;
	}
	return *this;
}

Span::~Span(void)
{
}

// member functions
void Span::addNumber(int num)
{
	if (database_.size() >= capacity_)
	{
		throw std::length_error("Span is full");
	}
	database_.push_back(num);
}

unsigned int Span::shortestSpan(void) const
{
	if (database_.size() < 2)
	{
		throw std::logic_error("Not enough numbers");
	}

	std::sort(database_.begin(), database_.end());

	unsigned int min_span = UINT_MAX;
	for (size_t i = 1; i < database_.size(); ++i)
	{
		const unsigned int span = database_[i] - database_[i - 1];
		if (span < min_span)
		{
			min_span = span;
		}
	}
	return min_span;
}

unsigned int Span::longestSpan() const
{
	if (database_.size() < 2)
	{
		throw std::logic_error("Not enough numbers");
	}

	int min = *database_.begin();
	int max = *database_.begin();
	for (std::vector<int>::const_iterator it = database_.begin(); it != database_.end(); ++it)
	{
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
	}
	return static_cast<unsigned int>(max - min);
}
