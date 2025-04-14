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
#include "../includes/Form.hpp"

int main()
{
    try
    {
        Bureaucrat a;
        Bureaucrat b("Bob", 1);
        Bureaucrat c("Tim", 80);
        Bureaucrat d(b);
        a = c;
        Form aF;
        Form bF("A21567", false, 20, 10);
        Form cF("A1452", false, 100, 100);
        Form dF(bF);
        aF = cF;
        std::cout << "\t***********" << std::endl;
        std::cout << b.getName() << " did a stupid thing and lost grade" << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        std::cout << "\t***********" << std::endl;
        std::cout << c.getName() << " was handed form " << cF.getName() << std::endl;
        c.signForm(cF);
        std::cout << c.getName() << " was excellent today so his grade goes up" << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        std::cout << "\t***********" << std::endl;
        // std::cout << "Copy of " << d.getName() << " was excellent today so his grade goes up" << std::endl;
        // d.incrementGrade();
        // std::cout << d << std::endl;
        // std::cout << "\t***********" << std::endl;
        std::cout << "Copy of " << a.getName() << " tried to sign form " << bF.getName() << std::endl;
        a.signForm(cF);
        std::cout << "For that silly mistake copy of " << a.getName() << " loses a grade" << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
        std::cout << "\t***********" << std::endl;
        std::cout << c.getName() << " did such a good job that let's bump his grade to 120" << std::endl;
        c.setGrade(120);
        std::cout << c << std::endl;
        std::cout << "\t***********" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
