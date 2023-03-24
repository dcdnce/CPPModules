/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:50:37 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/07 16:47:46 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("_no_name"), _grade(150){
	//std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()) {
	*this = src;
	//std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name){
	this->setGrade(grade);
	//std::cout << "Bureaucrat Values Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	//std::cout << "Bureaucrat Destructor called" << std::endl;
}

//////////////////////////////////////////// 

void		Bureaucrat::signForm(Form& form) {
	if (form.getIsSigned()) { 
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because : it is already signed." << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	} catch (std::exception& e) {
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because : ";
		std::cout << e.what();
	} 
}

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void) {
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void) {
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::setGrade(const int new_grade) {
	if (new_grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (new_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade = new_grade;
}

////////////////////////////////////////////

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	this->setGrade(src.getGrade());
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

