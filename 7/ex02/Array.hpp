#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{

private:
	T *_array;
	unsigned int _numOfElements;

public:
	Array() : _array(NULL), _numOfElements(0) {};
	Array(unsigned int n) : _array(new T[n]), _numOfElements(n) {};
	Array(const Array &other) : _array(new T[other._numOfElements]), _numOfElements(other._numOfElements)
	{
		for (unsigned int i = 0; i < this->_numOfElements; i++)
			this->_array[i] = other._array[i];
	};
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			this->_numOfElements = other._numOfElements;
			T *new_array = new T[this->_numOfElements];
			for (unsigned int i = 0; i < _numOfElements; i++)
				new_array[i] = other._array[i];
			delete[] this->_array;
			this->_array = new_array;
		}
		return *this;
	}
	~Array() { delete[] _array; };

	T &operator[](unsigned int index)
	{
		if (index >= _numOfElements)
			throw std::out_of_range("Index is out of bounds");
		return this->_array[index];
	}

	const T &operator[](unsigned int index) const // Add const overload
	{
		if (index >= _numOfElements)
			throw std::out_of_range("Index is out of bounds");
		return this->_array[index];
	}

	unsigned int size() const
	{
		return this->_numOfElements;
	}
};

#endif
