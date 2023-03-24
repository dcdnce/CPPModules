/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:13:26 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/15 21:31:36 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <exception>

int main() {
	Intern	someRandomIntern;
	Form*	form;

	try {
		form = someRandomIntern.makeForm("Robotomy Request", "Eric");
		std::cout << std::endl << *form << std::endl;
		delete form;
	} catch (std::exception& e){std::cerr << e.what();}

	try {
		form = someRandomIntern.makeForm("Presidential Pardon", "Eric");
		std::cout << std::endl << *form << std::endl;
		delete form;
	} catch (std::exception& e){std::cerr << e.what();}

	try {
		form = someRandomIntern.makeForm("Shrubbery Creation", "Eric");
		std::cout << std::endl << *form << std::endl;
		delete form;
	} catch (std::exception& e){std::cerr << e.what();}
	
	try {
		form = someRandomIntern.makeForm("Doesn't Exist", "Eric");
		std::cout << std::endl << *form << std::endl;
		delete form;
	} catch (std::exception& e){std::cerr << e.what();}

	return (0);
}
