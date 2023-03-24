/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:38 by pforesti          #+#    #+#             */
/*   Updated: 2022/03/05 12:19:35 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#define	A_PINK	"\e[38;5;225m"
#define	A_ESC	"\e[0m"

PhoneBook::PhoneBook(void) : _index(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addContact(void)
{
	if (this->_index == 8)
	{
		this->_index = 0;
		this->_contact[_index].eraseData();
	}
	this->_contact[_index].setData();
	this->_index++;
}

void	PhoneBook::displaySearch(void) const
{
	std::string	input;
	int			inputInt = 0;

	this->_displayHeader();
	for (size_t i = 0 ; i < 8 ; i++)
		this->_displayContact(i);
	while (!(inputInt > 0 && inputInt < 9)) 
	{
		std::cout << A_PINK << "Index : " << A_ESC; 
		std::getline(std::cin, input);
		inputInt = std::atoi(input.c_str());
		if (!(inputInt > 0 && inputInt < 9)) 
			std::cout << "\e[38;5;196mInvalid index." << A_ESC << std::endl;
	}
	this->_displaySearchContact((size_t)inputInt - 1);
}

void	PhoneBook::_displaySearchContact(size_t index) const 
{
	std::cout << A_PINK;
	for (int i = 0 ; i < 40 ; i++)
		std::cout << "_";
	std::cout << A_ESC << std::endl;
	for (int i = 0 ; i < 5 ; i++)
		std::cout << A_PINK << Contact::getField(i) << ": " << A_ESC << this->_contact[index].data[i] << std::endl;
	for (int i = 0 ; i < 40 ; i++)
		std::cout << "_";
	std::cout << std::endl;
}

void	PhoneBook::_displayHeader(void) const
{
	std::cout << A_PINK;
	std::cout << "|" << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRSTNAME" << "|";
	std::cout << std::setw(10) << "LASTNAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|" << std::endl;
	std::cout << A_ESC;
}

void	PhoneBook::_displayContact(size_t index) const
{
	std::cout << A_PINK << "|" << A_ESC;
	std::cout << std::setw(10) << index + 1;
	for (int i = 0 ; i < 3 ; i++)
	{
		std::cout << A_PINK << "|" << A_ESC;
		if (this->_contact[index].data[i].length() > 10)
			std::cout << this->_contact[index].data[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_contact[index].data[i];
	}
	std::cout << A_PINK << "|" << A_ESC << std::endl;
}


