/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:36:38 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 15:09:31 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	protected:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form(void);
		Form(const Form& src);
		Form(std::string name, int gradeToSign, int gradeToExec, std::string target);
		virtual ~Form(void);

		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& executor) const = 0; // Methode pure

		std::string	getName(void) const;
		std::string	getTarget(void) const;
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
