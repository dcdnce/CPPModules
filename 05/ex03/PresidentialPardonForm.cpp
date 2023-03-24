/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:31:04 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 16:09:12 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : 
	Form("Presidential Pardon", 25, 5, "_no_target")
{
	//std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	Form("Presidential Pardon", 25, 5, target)
{
	//std::cout << "PresidentialPardonForm Target Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_gradeToExec || executor.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());

	std::cout << this->_target << " was forgiven by Zaphod Beeblebrox" << std::endl;
}