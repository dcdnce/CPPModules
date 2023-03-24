/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:29:20 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/15 10:26:53 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	_value;
		static const int	_fbits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(const int tofix);
		Fixed(const float tofix);
		~Fixed(void);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;

		Fixed& operator=(Fixed const & r);
		Fixed operator+(Fixed const & r) const;
		Fixed operator-(Fixed const & r) const;
		Fixed operator*(Fixed const & r) const;
		Fixed operator/(Fixed const & r) const;

		bool operator>(Fixed const & r) const;
		bool operator<(Fixed const & r)	const ;
		bool operator<=(Fixed const & r) const;
		bool operator>=(Fixed const & r) const;
		bool operator==(Fixed const & r) const;
		bool operator!=(Fixed const & r) const;

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed& min(Fixed& l, Fixed& r); 
		static const Fixed& min(const Fixed& l, const Fixed& r); 
		static Fixed& max(Fixed& l, Fixed& r); 
		static const Fixed& max(const Fixed& l, const Fixed& r); 

};

std::ostream & operator<<(std::ostream & o, Fixed const & r);

#endif
