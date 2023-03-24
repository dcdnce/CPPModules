/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:57:59 by pforesti          #+#    #+#             */
/*   Updated: 2022/03/01 13:35:54 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	public:
		Contact(void);
		~Contact(void);
		static std::string	getField(int i);
		void				setData(void);
		void				eraseData(void);

		std::string			data[5];
	private:
		static std::string _fields[5];
};

#endif
