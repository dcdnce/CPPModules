/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:59:18 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/16 09:32:48 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int tofix) {
	//std::cout << "Int construtor called" << std::endl;
	this->_value = tofix * (1 << this->_fbits);
}

Fixed::Fixed(const float tofix) {
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(tofix * (1 << this->_fbits));
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);	
}

void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int Fixed::toInt(void) const {
	return (this->_value / ( 1 << this->_fbits));
}

float Fixed::toFloat(void) const {
	return ((float)this->_value / (float)(1 << this->_fbits));
}

/************/	/************/ 	/************/
/************/	/************/ 	/************/
/*			Comparison operators			*/

bool Fixed::operator<(Fixed const & r) const {
	return (this->getRawBits() < r.getRawBits());
}

bool Fixed::operator>(Fixed const & r) const {
	return (this->getRawBits() > r.getRawBits());
}

bool Fixed::operator>=(Fixed const & r) const {
	return (this->getRawBits() >= r.getRawBits());
}

bool Fixed::operator<=(Fixed const & r) const { 
	return (this->getRawBits() <= r.getRawBits());
}

bool Fixed::operator==(Fixed const & r) const {
	return (this->getRawBits() == r.getRawBits());
}

bool Fixed::operator!=(Fixed const & r) const {
	return (this->getRawBits() != r.getRawBits());
}

/************/	/************/ 	/************/
/************/	/************/ 	/************/
/*			Arithmetic operators			*/


Fixed & Fixed::operator=(Fixed const & r) {
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_value = r.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(Fixed const & r) const {
	return (Fixed(this->toFloat() + r.toFloat()));
}

Fixed Fixed::operator-(Fixed const & r) const {
	return (Fixed(this->toFloat() - r.toFloat()));
}

Fixed Fixed::operator*(Fixed const & r) const {
	return (Fixed(this->toFloat() * r.toFloat()));
}

Fixed Fixed::operator/(Fixed const & r) const {
	return (Fixed(this->toFloat() / r.toFloat()));
}

/************/ /************/ /************/
/************/ /************/ /************/

Fixed& Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed& Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	this->_value--;
	return (tmp);
}
/************/ /************/ /************/
/************/ /************/ /************/

std::ostream & operator<<(std::ostream & o, Fixed const & r) {
	o << r.toFloat();
	return (o);
}

Fixed& Fixed::min(Fixed& l, Fixed& r) {
	return (l < r ? l : r);
}

const Fixed& Fixed::min(const Fixed& l, const Fixed& r) {
	return (l < r ? l : r);
}

Fixed& Fixed::max(Fixed& l, Fixed& r) {
	return (l > r ? l : r);
}

const Fixed& Fixed::max(const Fixed& l, const Fixed& r) {
	return (l > r ? l : r);
}

