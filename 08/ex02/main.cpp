/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:13:41 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/20 15:49:21 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "MutantStack.hpp"

int main()
{
    std::cout << "STACK" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        std::cout << "--" <<std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite)
            std::cout << *it++ << std::endl;
        std::cout << "--" <<std::endl;

        MutantStack<int> s(mstack);
        it = s.begin();
        ite = s.end();
        while (it != ite)
            std::cout << *it++ << std::endl;
    }

    std::cout << "\nVECTOR" << std::endl;
    {
        std::vector<int> v;
        v.push_back(5);
        v.push_back(17);
        std::cout << v.back() << std::endl;
        v.pop_back();
        std::cout << v.size() << std::endl;
        std::cout << "--" <<std::endl;

        v.push_back(3);
        v.push_back(5);
        v.push_back(737);
        v.push_back(0);

        std::vector<int>::iterator it = v.begin();
        std::vector<int>::iterator ite = v.end();
        while (it != ite)
            std::cout << *it++ << std::endl;
        std::cout << std::endl;
    }

    return (0);
}