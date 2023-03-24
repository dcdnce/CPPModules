/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:07:38 by pforesti          #+#    #+#             */
/*   Updated: 2022/03/05 12:15:25 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

#define	A_PINK	"\e[38;5;225m"
#define	A_ESC	"\e[0m"

/*	Constructor	*/
/* - Init all 5 data fields	*/
Contact::Contact(void) {
	for (int i = 0 ; i < 5 ; i++)
		this->data[i].clear();
}

/*	Destructor	*/
Contact::~Contact(void) {
}

/*	Get data for the instance	*/
void	Contact::setData(void) {
	std::cout << A_PINK << "New Contact :" << A_ESC << std::endl;
	for (int i = 0 ; i < 5 ; i++)
	{
		std::cout << "\t" << Contact::getField(i) << ": ";
		std::getline(std::cin, this->data[i]);
		if (this->data[i].empty())
		{
			std::cout << "\t\e[38;5;196\e[4mFields cannot be empty.\e[0m" << std::endl;
			i--;
		}
	}
	std::cout << std::endl;
}

/*	Erase data for future use	*/
void	Contact::eraseData(void)
{
	for (int i = 0; i < 5 ; i++)
		this->data[i].clear();		
}

std::string Contact::_fields[5] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Number",
	"Secret",
};

std::string Contact::getField(int i) {
	return (Contact::_fields[i]);
}

