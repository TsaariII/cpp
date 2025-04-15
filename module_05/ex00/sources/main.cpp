/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:54:05 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 10:46:55 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat a;
    Bureaucrat b("Bob", 1);
    Bureaucrat c("Tim", 150);
    Bureaucrat d(b);
    a = c;
    try
    {
        std::cout << b.getName() << " did a stupid thing and lost grade" << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        std::cout << c.getName() << " was excellent today so his grade goes up" << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        std::cout << "Copy of " << d.getName() << " was excellent today so his grade goes up" << std::endl;
        d.incrementGrade();
        std::cout << d << std::endl;
        std::cout << "Copy of " << a.getName() << " did a stupid thing and lost grade" << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
        std::cout << c.getName() << " did such a good job that let's bump his grade to 120" << std::endl;
        c.setGrade(120);
        std::cout << c << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
