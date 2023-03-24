/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:47:02 by pforesti          #+#    #+#             */
/*   Updated: 2022/12/12 14:24:52 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm(void);

		virtual void	execute(Bureaucrat const & executor) const;
};