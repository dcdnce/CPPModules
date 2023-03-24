/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:31:04 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 16:09:12 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : 
	Form("Robotomy Request", 72, 45, "_no_target")
{
	//std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	Form("Robotomy Request", 72, 45, target)
{
	//std::cout << "RobotomyRequestForm Target Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_gradeToExec || executor.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());

	static	int count = 0;

	std::cout << "** drill noises **" << std::endl;
	if (!(count % 2))
		std::cout << this->_target << " has been robotomised" << std::endl;
	else
		std::cout << this->_target << " couldn't be robotomised" << std::endl;

	count++;
}