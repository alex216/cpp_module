#include <iostream>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

namespace {
	void addNumbers(Span& sp, std::vector<int>& numbers) {
		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
			sp.addNumber(*it);
		}
	}
}

int main()
{
	// Original test
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Original test:" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Test with 10000 random numbers
	Span big_span(10000);
	std::vector<int> random_numbers;
	random_numbers.reserve(10000);
	
	std::srand(std::time(0));
	for (int i = 0; i < 10000; ++i) {
		random_numbers.push_back(std::rand() % 100000);
	}
	
	addNumbers(big_span, random_numbers);
	
	std::cout << "\n10000 random numbers test:" << std::endl;
	std::cout << "Shortest span: " << big_span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << big_span.longestSpan() << std::endl;
	
	return 0;
}
