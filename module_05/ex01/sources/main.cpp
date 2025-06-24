/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:54:05 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 10:53:55 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
    Bureaucrat a;
    Bureaucrat b("Bob", 25);
    Bureaucrat c("Tim", 80);
    Bureaucrat d(b);
    a = c;
    std::cout << "to have name " << a.getName() << " and grade " << a.getGrade() << std::endl;
    std::cout << "\t***********" << std::endl;
    Form aF;
    Form bF("A21567", 20, 10);
    Form cF("A1452", 100, 100);
    Form dF(bF);
    aF = cF;
    std::cout << "\t***********" << std::endl;
    try
    {
        /* Form grade too high or too low */
        // Form tooHigh("Not this high", 0, 0);
        // Form tooLow("Not this low", 151, 151);
        
        /* Bureaucrat grade too low */
        // std::cout << b.getName() << " was handed form:\n" << bF << std::endl;
        // bF.beSigned(b);
        // std::cout << b.getName() << " did a stupid thing and lost grade" << std::endl;
        // b.decrementGrade();
        // std::cout << b << std::endl;
        // std::cout << "\t***********" << std::endl;
        
        /* Bureaucrat grade ok */
        std::cout << c.getName() << " was handed form:\n" << cF << std::endl;
        c.signForm(cF);
        std::cout << "Form " << cF.getName() << ":\n\tSigned status: " << cF.getSigned() << std::endl;
        std::cout << c.getName() << " was excellent today so his grade goes up" << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        std::cout << "\t***********" << std::endl;
        
        /* Form already signed */
        // std::cout << "Copy of " << a.getName() << " tried to sign form " << cF.getName() << std::endl;
        // a.signForm(cF);
        // std::cout << "For that silly mistake copy of " << a.getName() << " loses a grade" << std::endl;
        // a.decrementGrade();
        // std::cout << a << std::endl;
        // std::cout << "\t***********" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\t***********" << std::endl; 
    }
    return 0;
}
