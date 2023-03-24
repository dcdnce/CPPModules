/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:47:02 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 15:09:17 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	private:
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm(void);

		virtual void	execute(const Bureaucrat & executor) const;
};