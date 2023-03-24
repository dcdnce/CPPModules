/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:31:17 by pforesti          #+#    #+#             */
/*   Updated: 2022/03/01 16:53:39 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP 
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	addContact(void);
		void	displaySearch(void) const;

	private:
		void	_displayHeader(void) const;
		void	_displayContact(size_t index) const;
		void	_displaySearchContact(size_t index) const;
		void	_initContact(Contact contact);

		Contact _contact[8];
		size_t	_index;
};

#endif
