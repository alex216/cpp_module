#include <iostream>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <iomanip>
#include "Span.hpp"
#include "Span_multiset.hpp"

namespace {
	template<typename SpanType>
	void addNumbers(SpanType& sp, std::vector<int>& numbers) {
		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
			sp.addNumber(*it);
		}
	}
	
	double getTimeDiff(struct timeval start, struct timeval end) {
		return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
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
	
	// Performance comparison test
	std::cout << "\n=== Performance Comparison (Vector vs Multiset) ===" << std::endl;
	
	std::vector<int> test_numbers;
	test_numbers.reserve(10000);
	std::srand(12345); // Fixed seed for consistent results
	for (int i = 0; i < 10000; ++i) {
		test_numbers.push_back(std::rand() % 100000);
	}
	
	struct timeval start;
	struct timeval end;
	
	// Vector implementation test
	const Span vector_span(10000);
	gettimeofday(&start, NULL);
	addNumbers(const_cast<Span&>(vector_span), test_numbers);
	gettimeofday(&end, NULL);
	const double vector_add_time = getTimeDiff(start, end);
	
	gettimeofday(&start, NULL);
	const unsigned int vector_shortest = vector_span.shortestSpan();
	gettimeofday(&end, NULL);
	const double vector_shortest_time = getTimeDiff(start, end);
	
	gettimeofday(&start, NULL);
	const unsigned int vector_longest = vector_span.longestSpan();
	gettimeofday(&end, NULL);
	const double vector_longest_time = getTimeDiff(start, end);
	
	// Multiset implementation test
	const Span_multiset multiset_span(10000);
	gettimeofday(&start, NULL);
	addNumbers(const_cast<Span_multiset&>(multiset_span), test_numbers);
	gettimeofday(&end, NULL);
	const double multiset_add_time = getTimeDiff(start, end);
	
	gettimeofday(&start, NULL);
	const unsigned int multiset_shortest = multiset_span.shortestSpan();
	gettimeofday(&end, NULL);
	const double multiset_shortest_time = getTimeDiff(start, end);
	
	gettimeofday(&start, NULL);
	const unsigned int multiset_longest = multiset_span.longestSpan();
	gettimeofday(&end, NULL);
	const double multiset_longest_time = getTimeDiff(start, end);
	
	const std::string k_green = "\033[32m";
	const std::string k_red = "\033[31m";
	const std::string k_reset = "\033[0m";
	
	// Table header
	std::cout << "+----------------+-----------+-----------+" << std::endl;
	std::cout << "| Operation      |   Vector  | Multiset  |" << std::endl;
	std::cout << "|                |    (μs)   |   (μs)    |" << std::endl;
	std::cout << "+----------------+-----------+-----------+" << std::endl;
	
	// Add Numbers row
	std::cout << "| Add Numbers    |" 
	          << k_green << std::setw(10) << static_cast<int>(vector_add_time) << k_reset << " |"
	          << k_red << std::setw(10) << static_cast<int>(multiset_add_time) << k_reset << " |" 
	          << std::endl;
	
	// Shortest Span row
	std::cout << "| Shortest Span  |" 
	          << std::setw(10) << static_cast<int>(vector_shortest_time) << " |"
	          << std::setw(10) << static_cast<int>(multiset_shortest_time) << " |" 
	          << std::endl;
	
	// Longest Span row
	std::cout << "| Longest Span   |" 
	          << k_red << std::setw(10) << static_cast<int>(vector_longest_time) << k_reset << " |"
	          << k_green << std::setw(10) << static_cast<int>(multiset_longest_time) << k_reset << " |" 
	          << std::endl;
	
	// Table footer
	std::cout << "+----------------+-----------+-----------+" << std::endl;
	std::cout << "Results: Vector=" << vector_shortest << "/" << vector_longest 
	          << ", Multiset=" << multiset_shortest << "/" << multiset_longest << std::endl;
	
	return 0;
}
