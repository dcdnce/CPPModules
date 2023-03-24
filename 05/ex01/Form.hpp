/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:36:38 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/07 16:38:47 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form(void);
		Form(const Form& src);
		Form(std::string name, int gradeToSign, int gradeToExec);
		~Form(void);

		void		beSigned(const Bureaucrat& bureaucrat);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

		Form&	operator=(const Form& src);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("grade too high exception\n");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("grade too low exception\n");
				}
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
