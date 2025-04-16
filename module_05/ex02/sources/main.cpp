/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:54:05 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 17:14:43 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Bureaucrat.hpp"
// #include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat a;
    Bureaucrat b("Bob", 3);
    Bureaucrat c("Tim", 80);
    Bureaucrat d(b);
    a = c;
    std::cout << "to have name " << a.getName() << " and grade " << a.getGrade() << std::endl;
    std::cout << "\t***********" << std::endl;
    PresidentialPardonForm df;
    PresidentialPardonForm ppf1("Walter");
    try
    {
        std::cout << "\t***********" << std::endl;
        std::cout << b.getName() << " was handed form " << ppf1.getName() << std::endl;
        b.signAForm(ppf1);
        // std::cout << b.getName() << " did a stupid thing and lost grade" << std::endl;
        // b.decrementGrade();
        std::cout << b.getName() << " is ready to execute form " << ppf1.getName() << std::endl;
        b.executeForm(ppf1);
        std::cout << b << std::endl;
        std::cout << "\t***********" << std::endl;
        std::cout << c.getName() << " was handed form " << ppf1.getName() << std::endl;
        c.signAForm(ppf1);
        std::cout << c.getName() << " was excellent today so his grade goes up" << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        std::cout << "\t***********" << std::endl;
        // std::cout << "Copy of " << d.getName() << " was excellent today so his grade goes up" << std::endl;
        // d.incrementGrade();
        // std::cout << d << std::endl;
        // std::cout << "\t***********" << std::endl;
        // std::cout << "Copy of " << a.getName() << " tried to sign form " << ppf1.getName() << std::endl;
        // a.signAForm(cF);
        // std::cout << "For that silly mistake copy of " << a.getName() << " loses a grade" << std::endl;
        // a.decrementGrade();
        // std::cout << a << std::endl;
        // std::cout << "\t***********" << std::endl;
        // std::cout << c.getName() << " did such a good job that let's bump his grade to 120" << std::endl;
        // c.setGrade(120);
        // std::cout << c << std::endl;
        // std::cout << "\t***********" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\t***********" << std::endl;
    }
    return 0;
}
