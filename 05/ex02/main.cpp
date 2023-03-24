/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:13:26 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 16:37:53 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	PresidentialPardonForm pf("Eric");
	Bureaucrat a("Ferdinand", 150);
	Bureaucrat b("Roger", 1);
	a.executeForm(pf);
	b.executeForm(pf);
	std::cout << "-------------------------\n";

	RobotomyRequestForm rf("Eric");
	a.executeForm(rf);
	b.executeForm(rf);
	b.executeForm(rf);
	b.executeForm(rf);
	b.executeForm(rf);
	std::cout << "-------------------------\n";

	ShrubberyCreationForm sf("Forest");
	a.executeForm(sf);
	b.executeForm(sf);

}
