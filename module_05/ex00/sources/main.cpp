/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 07:54:05 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-11 07:54:05 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a;
        Bureaucrat b("Bob", 1);
        Bureaucrat c("Tim", 150);
        Bureaucrat d(b);
        a = c;
        std::cout << "Bob did a stupid thing and lost grade" << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        std::cout << "Tim was excellent today so his grade goes up" << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        std::cout << "Copy of Bob was excellent today so his grade goes up" << std::endl;
        d.incrementGrade();
        std::cout << d << std::endl;
        std::cout << "Copy of Tim did a stupid thing and lost grade" << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
        std::cout << "Tim did such a good job that let's bump his grade to 120" << std::endl;
        c.setGrade(120);
        std::cout << c << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
