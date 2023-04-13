/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:24:02 by pforesti          #+#    #+#             */
/*   Updated: 2023/04/12 11:26:59 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _expression(), _operands(), _result(0) {}
RPN::RPN(RPN const & src) {*this = src;}
RPN::~RPN() {}

bool    RPN::_isOperator(int const c) {
    return (c == '/' || c == '*' || c == '+' || c == '-');
}

void RPN::setExpression(std::string const expression) {
    this->_expression = expression;
}

void RPN::compute(void) {
    bool    opHasBeenMade = false;
    _operands = std::stack<int>();

    for (size_t i = 0 ; i < _expression.size() ; i++) {
        if (isspace(_expression[i])) {
            continue ;
        }
        else if (isdigit(_expression[i])) {
            _operands.push(_expression[i] - '0');
        }
        else if (_isOperator(_expression[i])) {
            if (_operands.size() < 2)
                throw std::exception();
            int op1 = _operands.top(); _operands.pop();
            int op2 = _operands.top(); _operands.pop();
            if (_expression[i] == '+') _operands.push(op2 + op1);
            if (_expression[i] == '-') _operands.push(op2 - op1);
            if (_expression[i] == '/') _operands.push(op2 / op1);
            if (_expression[i] == '*') _operands.push(op2 * op1);
            opHasBeenMade = true;
        }
        else {
            throw std::exception();
        }
    }
    _result = opHasBeenMade ? _operands.top() : 0;
}

std::string RPN::getExpression() const {
    return (_expression);
}

std::stack<int> RPN::getOperands() const {
    return (_operands);
}

int RPN::getResult() const {
    return (_result);
}

RPN& RPN::operator=(RPN const & rhs) {
    this->_expression = rhs.getExpression();
    this->_operands = rhs.getOperands();
    this->_result = rhs.getResult();
    return (*this);
}