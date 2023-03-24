/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:32:58 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/20 15:03:05 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class Span {
    private:
        size_t              _maxN;
        std::vector<int>    _data;
    public:
        Span(size_t const n);
        Span(Span const & src);
        ~Span(void);
        
        int     shortestSpan(void) const;
        int     longestSpan(void) const;
        void    print(void);
        void    addNumber(int const number);
        template <typename I>
        void    addNumber(I begin, I end) {
            I it = begin; 
            for (; it != end; it++) {
                if (_data.size() == _maxN)
                    throw (std::length_error("not enough space for range of iterators"));
                _data.push_back(*it);
            }
        }

        Span & operator=(Span const & src);
};