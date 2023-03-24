/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:31:04 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:14 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	Form("Shrubbery Creation", 145, 137, "_no_target")
{
	//std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	Form("Shrubbery Creation", 145, 137, target)
{
	//std::cout << "ShrubberyCreationForm Target Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_gradeToExec || executor.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());

	std::ofstream	ofs(this->_target + "_shrubbery");

	if (!ofs.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	ofs << "%%%,%%%%%%%\n"
	<< ",'%% \\-*%%%%%%%\n"
	<< ";%%%%%*%   _%%%%\"\n"
	<< ",%%%       \\(_.*%%%%.\n"
	<< "% *%%, ,%%%%*(    '\n"
	<< "%^     ,*%%% )\\|,%%*%,_\n"
	<< "*%    \\/ #).-\"*%%*\n"
	<< "_.) ,/ *%,\n"
	<< "_________/)#(_____________"
	<< std::endl;

	ofs.close();
}