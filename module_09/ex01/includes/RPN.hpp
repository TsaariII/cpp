/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:33 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/14 14:36:29 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<int> _Stack;
        bool _IsOperator(const std::string& symbol) const;
        int _Operator(const std::string& op, int a, int b) const;
        RPN(const RPN& copy);
        RPN& operator=(const RPN& copy);
    public:
        RPN();
        ~RPN();
        int evaluate(const std::string& expression);
};