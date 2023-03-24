/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:29:20 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/14 11:55:47 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	_value;
		static const int	_fbits = 8;
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed & operator=(Fixed const & r);
};

#endif
