/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:54:05 by nzharkev          #+#    #+#             */
/*   Updated: 2025/05/01 11:36:09 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Bureaucrat.hpp"
// #include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"
#include <memory>

int main()
{
    Bureaucrat a;
    Bureaucrat b("Bob", 3);
    Bureaucrat c("Tim", 60);
    Bureaucrat d(b);
    a = c;
    std::cout << "\t***********" << std::endl;
    Intern i1;
    Intern i2(i1);
    std::cout << "\t***********" << std::endl;
    try
    {
        std::unique_ptr<AForm> ppf1(i1.makeForm("presidential pardon", "Oscar"));
        std::cout << a.getName()  << " was handed form " << ppf1->getName() << std::endl;
        a.signAForm(*ppf1);
        //c.signAForm(*ppf1);
        a.executeForm(*ppf1);
        //c.executeForm(*ppf1);
        std::cout << "\t***********" << std::endl;
        std::unique_ptr<AForm> rrf1(i1.makeForm("robotomy request", "Oscar"));
        std::cout << b.getName()  << " was handed form " << rrf1->getName() << std::endl;
        b.signAForm(*rrf1);
        // c.signAForm(*rrf1);
        b.executeForm(*rrf1);
        std::cout << "\t***********" << std::endl;
		std::unique_ptr<AForm> scf1(i1.makeForm("shrubbery", "Park"));
        std::cout << b.getName()  << " was handed form " << scf1->getName() << std::endl;
        b.signAForm(*scf1);
        b.executeForm(*scf1);
		std::cout << "\t***********" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\t***********" << std::endl;
    }
    return 0;
}
