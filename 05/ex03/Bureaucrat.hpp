/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:46:02 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 16:23:20 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP 
#define BUREAUCRAT_HPP 

#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	class GradeTooHighException : public std::exception {
		public: 
			virtual const char* what() const throw() {
				return ("exception: tried to assign a new grade that is too high\n");
			}
	};
	class GradeTooLowException : public std::exception {
		public: 
			virtual const char* what() const throw() {
				return ("exception: tried to assign a new grade that is too low\n");
			}
	};

	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat(const std::string name, const int grade);
		~Bureaucrat(void);
		
		void		signForm(Form& form);
		void		executeForm(Form const & form);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		setGrade(const int new_grade);

		Bureaucrat & operator=(const Bureaucrat & src);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif
