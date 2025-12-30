#include "Fixed.hpp"

// constructors -------------------------------

Fixed::Fixed() : FP_value(0) {}

Fixed::Fixed(const Fixed &copy) {
	*this = copy;
}

Fixed::Fixed(const int value) {
	this->FP_value = value << this->frac_bits;
}

Fixed::Fixed(const float value) {
	this->FP_value = (int)roundf(value * (1 << this->frac_bits));
}

// operators ------------------------------

Fixed &Fixed::operator=(const Fixed &copy) {
	if (this != &copy) {
		this->FP_value = copy.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &op_stream, Fixed const &obj) {
	op_stream << obj.toFloat();
	return op_stream;
}

bool Fixed::operator>(const Fixed &copy) const {
	return (this->getRawBits() > copy.getRawBits());
}

bool Fixed::operator<(const Fixed &copy) const{
	return (this->getRawBits() < copy.getRawBits());
}

bool Fixed::operator>=(const Fixed &copy) const{
	return (this->getRawBits() >= copy.getRawBits());
}

bool Fixed::operator<=(const Fixed &copy) const{
	return (this->getRawBits() <= copy.getRawBits());
}

bool Fixed::operator==(const Fixed &copy) const{
	return (this->getRawBits() == copy.getRawBits());
}

bool Fixed::operator!=(const Fixed &copy) const{
	return (this->getRawBits() != copy.getRawBits());
}

Fixed Fixed::operator+(const Fixed&copy) const {
	Fixed	_new;
	_new.FP_value = this->FP_value + copy.getRawBits();
	return _new;
}

Fixed Fixed::operator-(const Fixed &copy) const {
	Fixed	_new;
	_new.FP_value = this->FP_value - copy.getRawBits();
	return _new;
}

Fixed Fixed::operator*(const Fixed &copy) const {
	Fixed	_new;
	long long tmp = (long long)(this->FP_value * copy.getRawBits());
	_new.setRawBits(tmp >> this->frac_bits);
	return _new;
}

Fixed Fixed::operator/(const Fixed &copy) const {
	Fixed _new;
	long long tmp = (this->FP_value << this->frac_bits);
	if (copy.getRawBits() != 0)
		_new.setRawBits(tmp / copy.getRawBits());
	else
		std::cerr << "0 detected\n";
	return _new;
}

Fixed	&Fixed::operator++(void) {
	this->FP_value++;
	return *this;
}

Fixed	&Fixed::operator--(void) {
	this->FP_value--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	int tmp = this->getRawBits();
	this->FP_value++;
	return tmp;
}

Fixed	Fixed::operator--(int) {
	int tmp = this->getRawBits();
	this->FP_value--;
	return tmp;
}

// destructor-------

Fixed::~Fixed() {}

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

void	Fixed::setRawBits(int const raw) {
	this->FP_value = raw;
}
