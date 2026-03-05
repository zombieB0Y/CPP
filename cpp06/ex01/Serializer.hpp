#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.h"

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &copy);
	~Serializer();

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};
