/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:45:10 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/07 16:43:46 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) :
		_name("_no_name"),
		_isSigned(false),
		_gradeToSign(150),
		_gradeToExec(150)
{
	//std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const Form& src) :
		_name(src.getName()),
		_isSigned(false),
		_gradeToSign(src.getGradeToSign()),
		_gradeToExec(src.getGradeToExec())
{
	//std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
		_name(name),
		_isSigned(false),
		_gradeToSign(gradeToSign),
		_gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw (Form::GradeTooHighException());
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw (Form::GradeTooLowException());
	//std::cout << "Form Name Constructor called" << std::endl;
}

Form::~Form(void) {
	//std::cout << "Form Default Destructor called" << std::endl;
}

////////////////////////////////////////////


void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw(Form::GradeTooLowException());
	this->_isSigned = true;
}

bool	Form::getIsSigned(void) const{
	return (this->_isSigned);
}

std::string		Form::getName(void) const{
	return (this->_name);
}

int		Form::getGradeToSign(void) const{
	return (this->_gradeToSign);
}

int		Form::getGradeToExec(void) const{
	return (this->_gradeToExec);
}

//////////////////////////////////////////

Form&			Form::operator=(const Form& src) {
	this->_isSigned = src.getIsSigned();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& f) {
	os << "form name: "<< f.getName() << std::endl;
	os << "form is signed: "<< (f.getIsSigned() ? "true" : "false") << std::endl;
	os << "form grade to sign: "<< f.getGradeToSign() << std::endl;
	os << "form grade to exec: "<< f.getGradeToExec() << std::endl;
	return (os);
}
