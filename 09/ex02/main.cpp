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

#include "VectorFjmi.hpp"
#include "ListFjmi.hpp"

static inline int printError(void);
template<typename T>
static inline bool isSorted(T array);
static inline void print(std::string const state, std::vector<size_t> sequence);

int main(int ac, char *av[])
{
    if (ac <= 2)
        return (printError());

    VectorFjmi    VectorFjmi;
    ListFjmi    ListFjmi;
	
    try {
        for (int i = 1 ; i < ac ; i++)	
        {
            if (av[i][0] == '-')
                throw std::exception();
            size_t num = std::stoul(av[i]);
            VectorFjmi.sequence.push_back(num);
            ListFjmi.sequence.push_back(num);
        }
        print("Before: ", VectorFjmi.sequence);
        VectorFjmi.sort();
        ListFjmi.sort();
        print("After: ", VectorFjmi.sequence);
        VectorFjmi.printDuration();
        ListFjmi.printDuration();
        if (!isSorted(VectorFjmi.sequence) || !isSorted(ListFjmi.sequence))
            throw std::exception();
    } catch (std::exception & e) {return(printError());}

    return (0);
}

static inline int printError(void)
{
    std::cerr << "Error" << std::endl;
    return (1);
}

template<typename T>
static inline bool isSorted(T array)
{
    typename T::iterator it1 = array.begin();
    typename T::iterator it2 = array.begin();
    std::advance(it2, 1);
    for (size_t i = 1; i < array.size() ; i++)
    {
        if (*(it1) > *it2)
            return (false);
        it1++;
        it2++;
    }
    return (true);
}

static inline void	print(std::string const state, std::vector<size_t> sequence)
{
	std::cout << state;
	for (size_t i = 0 ; i < (sequence.size() <= 10 ? sequence.size() : 5) ; i++)
		std::cout << " " << sequence[i];
	if (sequence.size() > 10)
		std::cout << " [...]";
	std::cout << std::endl;
}