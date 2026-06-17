#pragma once

#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(const T &arr, const int x) {
	typename T::const_iterator	it = arr.begin();
	typename T::const_iterator f = std::find(it, arr.end(), x);
	if (f == arr.end())
		throw std::exception();
	return f;
}