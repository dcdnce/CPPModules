/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:00:07 by pforesti          #+#    #+#             */
/*   Updated: 2023/06/29 15:56:47by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

#include "FJMI.hpp"

static inline int printError(void);
template<typename T>
static inline bool isSort(T array);

int main(int ac, char *av[])
{
    if (ac <= 2)
        return (printError());

    FJMI    fjmi;

	for (int i = 1 ; i < ac ; i++)	
	{
		if (av[i][0] == '-')
			throw std::exception();
		fjmi.sequence.push_back(std::stoul(av[i]));
	}

    try {
        fjmi.startChrono();
        fjmi.sort();
        fjmi.endChrono();
        fjmi.printBefore();
        fjmi.printAfter();
        fjmi.printDuration();
    } catch (std::exception & e) {return(printError());}

    return (0);
}

static inline int printError(void)
{
    std::cerr << "Error" << std::endl;
    return (1);
}

template<typename T>
static inline bool isSort(T array)
{
    for (typename T::iterator it = array.begin() + 1; it != array.end() ; it++)
        if (*(it - 1) > *it)
            return (false);
    return (true);
}