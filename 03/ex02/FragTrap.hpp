/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:27:31 by pforesti          #+#    #+#             */
/*   Updated: 2022/11/17 14:52:54 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& src);
	~FragTrap(void);

	void	highFiveGuys(void);
};

#endif