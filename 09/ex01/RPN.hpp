/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:29:54 by pforesti          #+#    #+#             */
/*   Updated: 2023/04/12 10:58:35 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

class RPN {
    private:
        std::string         _expression;
        std::stack<int>     _operands;
        int                 _result;
        bool    _isOperator(int const c);
    public:
        RPN();
        RPN(RPN const & src);
        ~RPN();

        void     compute();
        
        void            setExpression(std::string const expression);
        std::string         getExpression() const;
        std::stack<int>     getOperands() const;
        int                 getResult() const;

        RPN & operator=(RPN const & rhs);
};