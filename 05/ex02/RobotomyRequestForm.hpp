/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:47:02 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 14:24:52 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form {
	private:
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm(void);

		virtual void	execute(Bureaucrat const & executor) const;
};