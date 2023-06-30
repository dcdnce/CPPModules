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
#include <exception>

#include "PmergeMe.hpp"
#include "PmergeMe.hpp"

void    parse(PmergeMe & pmm, int ac, char *av[]);
static inline int printError(const char* error);
template<typename T>
static inline bool isSorted(T array);
static inline void	print(std::string const state, std::vector<size_t> & sequence);


int main(int ac, char *av[])
{
    if (ac <= 2)
        return (printError("Not enough arguments"));

    PmergeMe    pmm;
	
    try {
        parse(pmm, ac, av);
        print("Before: ", pmm.vector_sequence);
        pmm.sort();
        print("After: ",pmm.vector_sequence);
	    std::cout << "Time to process a range of " << pmm.vector_sequence.size() << " with std::vector: " << pmm.vector_duration << " s" << std::endl;
	    std::cout << "Time to process a range of " << pmm.list_sequence.size() << " with std::list: " << pmm.list_duration << " s" << std::endl;
        if (!isSorted(pmm.vector_sequence) || !isSorted(pmm.list_sequence))
            throw std::runtime_error("Sequence is not sorted");
    } catch (std::exception & e) {return(printError(e.what()));}

    return (0);
}

void    parse(PmergeMe & pmm, int ac, char *av[])
{
    for (int i = 1 ; i < ac ; i++)	
    {
        if (av[i][0] == '-')
            throw std::runtime_error("Negative number");
        size_t num = std::stoul(av[i]);
        pmm.vector_sequence.push_back(num);
        pmm.list_sequence.push_back(num);
    }
}

static inline int printError(const char* error)
{
    std::cerr << "Error: " << error << std::endl;
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
        {
            std::cout << *it1 << " > " << *it2 << std::endl;
            return (false);
        }
        it1++;
        it2++;
    }
    return (true);
}

static inline void	print(std::string const state, std::vector<size_t> & sequence)
{
	std::cout << state;
	for (size_t i = 0 ; i < (sequence.size() <= 10 ? sequence.size() : 5) ; i++)
		std::cout << " " << sequence[i];
	if (sequence.size() > 10)
		std::cout << " [...]";
	std::cout << std::endl;
}
