#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	size_t	n;
	T		*arr;
public:
	Array() {
		this->arr = new T[0];
		n = 0;
	}
	Array(const Array &copy) {
		this->arr = 0;
		*this = copy;
	}
	Array   &operator=(const Array &copy) {
		if (this != &copy) {
			T	*_new = new T[copy.size()]();
			for (size_t i = 0; i < copy.size(); i++) {
				_new[i] = copy.arr[i];
			}
			delete[] this->arr;
			this->arr = _new;
			this->n = copy.size();
		}
		return *this;
	}
	T	&operator[](const size_t idx) {
		if (idx >= n)
			throw std::exception();
		return this->arr[idx];
	}
	~Array() {
		delete[] this->arr;
	}

	Array(const size_t n) {
		this->arr = new T[n]();
		this->n = n;
	}
	size_t	size() const {
		return n;
	}
};


// obj1 = obj2;
