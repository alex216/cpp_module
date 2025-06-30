#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T & min(T &left, T &right)
{
	return left < right ? left : right;
}

template <typename T>
T const & min(T const &left, T const &right)
{
	return left < right ? left : right;
}

template <typename T>
T & max(T &left, T &right)
{
	return left > right ? left : right;
}

template <typename T>
T const & max(T const &left, T const &right)
{
	return left > right ? left : right;
}

#endif
