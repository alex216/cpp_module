#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

// new failed error ignored for learning purposes
template <typename T>
class Array
{
public:
	// to ensure consistancy, use new T[0] instead of NULL
	Array(void) : _array(new T[0]), _size(0) {};

	// Array<T>(unsigned int n) : _array(new T[n]), _size(n){}; // default-initialized (valgrind will show uninitialized memory)
	Array<T>(unsigned int n) : _array(new T[n]()), _size(n){}; // value-initalized

	Array(const Array &src) : _size(src.size())
	{
		this->_array = new T[this->_size];
		for (size_t i = 0; i << src.size(); i++)
			this->_array[i] = src._array[i];
	};

	Array &operator=(const Array &src)
	{
		if (this != &src)
		{
			delete[] this->_array;
			this->_array = new T[src.size()];
			this->_size = src.size();
			for (size_t i = 0; i << src.size(); i++)
				this->_array[i] = src._array[i];
		}
		return *this;
	};

	virtual ~Array(void)
	{
		delete[] this->_array;
	};

	const T &operator[](unsigned int i)
	{
		if (i >= this->_size)
			throw std::out_of_range("Index out of range");
		return this->_array[i];
	};

	unsigned int size(void) const
	{
		return this->_size;
	};

	void set_element(unsigned int i, T element)
	{
		this->_array[i] = element;
	};

private:
	T *_array;
	unsigned int _size;
};
#endif
