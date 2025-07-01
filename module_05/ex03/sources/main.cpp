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
        if (!ppf1)
        {
            std::cerr << "Failed to create from.\n";
            return 1;
        }
        std::cout << a.getName()  << " was handed form:\n" << *ppf1 << std::endl;
        // a.signAForm(*ppf1);
        b.signAForm(*ppf1);
        // a.executeForm(*ppf1);
        b.executeForm(*ppf1);
        std::cout << "\t***********" << std::endl;
        std::unique_ptr<AForm> rrf1(i1.makeForm("robotomy request", "Oscar"));
        if (!rrf1)
        {
            std::cerr << "Failed to create from.\n";
            return 1;
        }
        std::cout << b.getName()  << " was handed form:\n" << *rrf1 << std::endl;
        b.signAForm(*rrf1);
        // c.signAForm(*rrf1);
        b.executeForm(*rrf1);
        std::cout << "\t***********" << std::endl;
		std::unique_ptr<AForm> scf1(i1.makeForm("shrubbery", "Park"));
        if (!scf1)
        {
            std::cerr << "Failed to create from.\n";
            return 1;
        }
        std::cout << b.getName()  << " was handed form:\n" << *scf1 << std::endl;
        b.signAForm(*scf1);
        b.executeForm(*scf1);
		std::cout << "\t***********" << std::endl;
        std::string forms[] = {"presidential pardon", "robotomy request", "stupid form", "shrubbery"};
        for (int i = 0; i < 4; ++i)
        {
            std::unique_ptr<AForm> form(i1.makeForm(forms[i], "Test"));
            if (form)
                std::cout << *form << std::endl;
            else
                std::cerr << "Form creation failed for name: " << forms[i];
            std::cout << "\t***********" << std::endl;
        }
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\t***********" << std::endl;
    }
    return 0;
}
