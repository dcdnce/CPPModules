/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:01:26 by pforesti          #+#    #+#             */
/*   Updated: 2023/01/16 15:05:46 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>

template<typename T>
class Array {
    private:
        size_t  _size;
        T*      _data;

    public:
        //CONSTRUCTEURS
        Array<T>(void) : _size(0), _data(nullptr){}
        Array<T>(size_t const n) : _size(n), _data(nullptr) {
            if (_size > 0)
                _data = new T[_size];
        }
        Array<T>(Array<T> & src) : _size(0), _data(nullptr) {
            *this = src;
        }

        //DESTRUCTEUR
        ~Array<T>(void) {
            delete[] _data;
        };
        
        //GETTERS
        size_t  size(void) const {
            return (_size);
        }
        
        //Operateur d'affectation
        Array<T> & operator=(Array<T> & src) {
            if (this == &src)
                return (*this);

            if (_data != nullptr)
                delete[] _data;
            _data = nullptr;
            _size = src.size();
            if (_size > 0)
                _data = new T[_size];
            for (size_t i = 0 ; i < _size ; i++)
                _data[i] = src[i];
            
            return (*this);
        }

        //Operateur []
        T & operator[](size_t i) const{
            if (i >= _size)
                throw std::out_of_range("index out of range exception");
            return (_data[i]);
        }
};

template<typename T>
std::ostream & operator<<(std::ostream & os, Array<T> const & src) {
    os << "[";
    for (size_t i = 0 ; i < src.size() ; i++) {
        os << src[i];
        if (i != src.size() - 1)
            os << ", ";
    }
    os << "]";
    return (os);
}