#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
	size_t	n;
	T		*arr;
public:
	Array() {
		this->arr = new T();
		n = 1;
	}
	Array(const Array &copy) {

	}
	Array   &operator=(const Array &copy);
	~Array();

	Array(const size_t n) {
		this->arr = new T[n]();
		this->n = n;
	}
	size_t	size() {
		return n;
	}
};


// obj1 = obj2;
