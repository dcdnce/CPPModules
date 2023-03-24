/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:13:26 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/05 16:02:17 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "Constructors exceptions :" << std::endl;
	try {
		Bureaucrat	tooLow("Eric", 151);
	} catch (const std::exception& e) {
		std::cerr << e.what();
	}
	try {
		Bureaucrat	tooHigh("Thierry", 0);
	} catch (const std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << std::endl << "Methods exceptions :" << std::endl;
	Bureaucrat	robert("Robert", 1);
	std::cout << robert << std::endl;;
	try {
		robert.incrementGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << robert << std::endl;;

	return (0);
}
