#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
    int stored_value;
    static const int stored_frac = 8;

public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &copy);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};