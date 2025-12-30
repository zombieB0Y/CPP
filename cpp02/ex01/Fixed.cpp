#include "Fixed.hpp"

// constructors -------------------------------
Fixed::Fixed() : FP_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->FP_value = value << this->frac_bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->FP_value = (int)roundf(value * (1 << this->frac_bits));
}

// operators ------------------------------

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->FP_value = copy.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &op_stream, Fixed const &obj) {
	// std::cout << "Insert operator called" << std::endl;
	op_stream << obj.toFloat();
	return op_stream;
}

// destructor-------

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// member fucntions-----------------

float Fixed::toFloat( void ) const {
	return ((float)FP_value / (1 << frac_bits));
}

int Fixed::toInt( void ) const {
	return (FP_value >> frac_bits);	
}

int Fixed::getRawBits(void) const {
	return this->FP_value;
}

void	Fixed::setRawBits(int const raw) `{
	this->FP_value = raw;
}
