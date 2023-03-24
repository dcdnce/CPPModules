/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:14:28 by pforesti          #+#    #+#             */
/*   Updated: 2022/03/05 12:17:49 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define	A_PINK	"\e[38;5;225m"
#define	A_ESC	"\e[0m"

int	main(void)
{
	PhoneBook 	pb;
	std::string	input;

	while (1)
	{
		std::cout << A_PINK;
		std::cout << "\e[5m=== Incredible Phonebook Alpha v0.08 ===\e[0m" << std::endl;
		std::cout << "\e[38;5;223mACTION: ";
		std::cout << A_ESC;
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
			pb.addContact();
		else if (!input.compare("SEARCH"))
			pb.displaySearch();
		else if (!input.compare("EXIT"))
			return (0);
		input.clear();
	}
	return (0);
}
