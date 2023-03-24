/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:30:21 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/15 21:21:56 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <iostream>

class Intern {
	private:
		Form*	_makeShrubbery(const std::string target);
		Form*	_makeRobotomy(const std::string target);
		Form*	_makePresidential(const std::string target);
	public:
		Intern(void);
		Intern(const Intern& src);
		~Intern();
		
		Form*	makeForm(const std::string formName, const std::string formTarget);

		Intern&	operator=(const Intern& src);

		class NoFormNameException : public std::exception {
			virtual const char* what() const throw() {
					return ("Given form name doesn't match any known form exception\n");
			}
		};
};
