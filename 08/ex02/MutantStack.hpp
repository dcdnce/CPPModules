/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:14:20 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/20 15:40:21 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    private:
    public:
        MutantStack(void) {}
        MutantStack(MutantStack<T> const & cpy) {*this = cpy;}
        ~MutantStack(void) {};
        
        MutantStack<T>& operator=(MutantStack<T> const & rhs) {
            if (this != &rhs)
                this->c = rhs.c;
            return (*this);
        }
        
        // typename -> dynamic
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void) {
            return (this->c.begin());
        }
        iterator end(void) {
            return (this->c.end());
        }
};