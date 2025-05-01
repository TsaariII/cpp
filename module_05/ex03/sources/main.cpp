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
    AForm* ppf1;
    AForm* rrf1;
    try
    {
        ppf1 = i1.makeForm("presidential pardon", "Oscar");
        std::cout << b.getName()  << " was handed form " << ppf1->getName() << std::endl;
        b.signAForm(*ppf1);
        b.executeForm(*ppf1);
        std::cout << "\t***********" << std::endl; 
        rrf1 = i1.makeForm("robotomy request", "Oscar");
        std::cout << b.getName()  << " was handed form " << rrf1->getName() << std::endl;
        b.signAForm(*rrf1);
        b.executeForm(*rrf1);
        std::cout << "\t***********" << std::endl; 
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\t***********" << std::endl;
    }
    delete ppf1;
    delete rrf1;
    return 0;
}

/*
Beraucrat
    Default
    Constructor
    Copy
    Assignment
    Sign form
    Execute form
President
    Default
    Constructor
    Copy
    Assignment
    Sign execption
    Execute exeception
Robotomy
    Default
    Constructor
    Copy
    Assignment
    Sign execption
    Execute exeception 
Shrubbery
    Default
    Constructor
    Copy
    Assignment
    Sign execption
    Execute exeception
*/