#pragma once

#include <iostream>
#include <cstdint>

class Serialize
{
private:
	
public:
	Serialize();
	Serialize(const Serialize &copy);
	Serialize   &operator=(const Serialize &copy);
	~Serialize();


	static uintptr_t	serialize(Data *ptr);
};
