/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:39:53 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/14 14:48:02 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) : _Stack(copy._Stack) {}

RPN& RPN::operator=(const RPN& copy)
{
    if (this != &copy)
    {
        _Stack = copy._Stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression)
{
    std::istringstream stream(expression);
    std::string token;
    while (stream >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
            _Stack.push(token[0] - 48);
        else if (_IsOperator(token))
        {
            if (_Stack.size() < 2)
                throw std::runtime_error("Error: Not enough operands");
            int b = _Stack.top(); _Stack.pop();
            int a = _Stack.top(); _Stack.pop();
            int result = _Operator(token, a, b);
            _Stack.push(result);
        }
        else
            throw std::runtime_error("Error");
    }
    if (_Stack.size() != 1)
        throw std::runtime_error("Error: malformed expression");
    return _Stack.top();
}

bool RPN::_IsOperator(const std::string& symbol) const { return symbol == "+" || symbol == "-" || symbol == "*" ||symbol == "/"; }

int RPN::_Operator(const std::string& op, int a, int b) const
{
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: Unknown operator");
}