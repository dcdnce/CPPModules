/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:16:09 by pforesti          #+#    #+#             */
/*   Updated: 2022/04/18 16:09:46 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <string>

class Harl {
	private:
		std::string	_indices[4];
		void	(Harl::*_foo[4])(void);
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
