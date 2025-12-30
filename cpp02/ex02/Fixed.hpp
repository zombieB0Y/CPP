#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int FP_value;
	static const int frac_bits = 8;

public:
	// constr
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);

	Fixed	&operator=(const Fixed &copy);
	bool	operator>(const Fixed &copy) const;
	bool	operator<(const Fixed &copy) const;
	bool	operator>=(const Fixed &copy) const;
	bool	operator<=(const Fixed &copy) const;
	bool	operator==(const Fixed &copy) const;
	bool	operator!=(const Fixed &copy) const;
	Fixed	operator+(const Fixed &copy) const;
	Fixed	operator-(const Fixed &copy) const;
	Fixed	operator*(const Fixed &copy) const;
	Fixed	operator/(const Fixed &copy) const;
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);




	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &op_stream, Fixed const &obj);