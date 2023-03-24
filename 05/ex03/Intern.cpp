/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:45:46 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/15 21:28:20 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void) {} 

Intern::Intern(const Intern& src) {
	(void)src;
}

Intern::~Intern(void) {}

Form* makePresidential(const std::string target) {
	return (new PresidentialPardonForm(target));
}

Form* makeRobotomy(const std::string target) {
	return (new RobotomyRequestForm(target));
}

Form* makeShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

Intern& Intern::operator=(const Intern& src) {
	(void)src;
	return (*this);
}

Form* Intern::makeForm(const std::string formName, const std::string formTarget) {
	std::string forms[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	Form *(*f[])(const std::string) = {makeShrubbery, makeRobotomy, makePresidential};

	for (int i = 0 ; i < 3 ; i++) {
		if (forms[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return ((f[i])(formTarget));
		}
	}

	throw(Intern::NoFormNameException());
	return (nullptr);
}