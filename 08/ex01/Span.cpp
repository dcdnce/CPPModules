/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:46 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/20 14:32:59by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <stdexcept>
#include "Span.hpp"

Span::Span(size_t const n) : _maxN(n) {}

Span::Span(Span const & src) {*this = src;}

Span::~Span(void) {}

void Span::addNumber(int const number) {
    if (_data.size() == _maxN)
        throw (std::length_error("span limit exceeded"));
    _data.push_back(number);
}

int Span::shortestSpan(void) const {
    if (_data.size() < 2)
        throw (std::length_error("not enough value to compute span"));

    int ans = std::numeric_limits<int>::max();
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());
    for (size_t i = 0 ; i < sorted.size() - 1 ; i++)
        ans = std::min(ans, sorted[i+1] - sorted[i]);
    return (ans);
}

int Span::longestSpan(void) const {
    if (_data.size() < 2)
        throw (std::length_error("not enough value to compute span"));

    int ans = 0;
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());
    ans = sorted.back() - sorted[0];
    return (ans);
}

Span & Span::operator=(Span const & src) {
    if (this == &src)
        return (*this);
    this->_maxN = src._maxN;
    this->_data = src._data;
    return (*this);
}

void Span::print(void) {
    size_t  i = 0;
    for (i = 0 ; i < _data.size() && i < 10 ; i++)
        std::cout << _data[i] << " ";
    if (i == 10 && _data.size() > 10)
        std::cout << "... " << _data.back();
	std::cout << std::endl;
    std::cout << "shortestSpan : " << this->shortestSpan() << std::endl;
	std::cout << "longestSpan : " << this->longestSpan() << std::endl;
	std::cout << std::endl;
}
