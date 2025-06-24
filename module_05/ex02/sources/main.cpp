/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:54:05 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/17 14:41:19 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Bureaucrat.hpp"
// #include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
    /* To show that AForm class is abstract */
    // AForm aForm;

    Bureaucrat a;
    Bureaucrat b("Bob", 3);
    Bureaucrat c("Tim", 60);
    Bureaucrat d(b);
    a = c;
    std::cout << "\t***********" << std::endl;
    ShrubberyCreationForm scf;
    ShrubberyCreationForm scf1("park");
    ShrubberyCreationForm scf2(scf1);
    scf = scf1;
    std::cout << "\t***********" << std::endl;
    RobotomyRequestForm rrf;
    RobotomyRequestForm rrf1("Toby");
    RobotomyRequestForm rrf2(rrf1);
    rrf = rrf1;
    std::cout << "\t***********" << std::endl;
    PresidentialPardonForm pf;
    PresidentialPardonForm ppf1("Walter");
    PresidentialPardonForm ppf2(ppf1);
    pf = ppf1;
    std::cout << "\t***********" << std::endl;
    try
    {
        std::cout << a.getName() << " has way too high grade (" << a.getGrade() << ") so let's correct that to 120" << std::endl;
        a.setGrade(120);
        /* Grade too low to sign */
        // std::cout << a.getName() << " was handed form:\n" << ppf1 << std::endl;
        // a.signAForm(ppf1);
        // std::cout << a.getName() << " was handed form:\n" << rrf1 << std::endl;
        // a.signAForm(rrf1);

        /* Grade ok for Shrubbery */
        std::cout << a.getName() << " was handed form:\n" << scf1 << std::endl;
        a.signAForm(scf1);
        std::cout << "Form " << scf1.getName() << ":\n\tSigned status: " << scf1.getSigned() << std::endl;
        std::cout << a.getName() << " is ready to execute form " << scf1.getName() << std::endl;
        a.executeForm(scf1);
        std::cout << a.getName() << " did what was asked so his grade goes up" << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        std::cout << "\t***********" << std::endl;

        // std::cout << c.getName() << " was handed form:\n" << ppf1 << std::endl;
        // c.signAForm(ppf1);

        /* Grade ok to sign Robotomy */
        std::cout << c.getName() << " was handed form:\n" << rrf1 << std::endl;
        c.signAForm(rrf1);

        /* Grade too low to execute Robotomy*/
        // std::cout << c.getName() << " is ready to execute form " << rrf1.getName() << std::endl;
        // c.executeForm(rrf1);

        std::cout << c.getName() << " was handed form " << scf2.getName() << std::endl;
        c.signAForm(scf2);
        std::cout << "Form " << scf2.getName() << ":\n\tSigned status: " << scf2.getSigned() << std::endl;
        std::cout << c.getName() << " is ready to execute form " << scf2.getName() << std::endl;
        c.executeForm(scf2);
        std::cout << c << std::endl;
        std::cout << "\t***********" << std::endl;

        std::cout << b.getName() << " was handed form:\n" << ppf1 << std::endl;
        b.signAForm(ppf1);
        std::cout << "Form " << ppf1.getName() << ":\n\tSigned status: " << ppf1.getSigned() << std::endl;
        std::cout << b.getName() << " is ready to execute form " << ppf1.getName() << std::endl;
        b.executeForm(ppf1);
        std::cout << b.getName() << " was handed form " << rrf2.getName() << std::endl;
        b.signAForm(rrf2);
        std::cout << "Form " << rrf2.getName() << ":\n\tSigned status: " << rrf2.getSigned() << std::endl;
        std::cout << b.getName() << " is ready to execute form " << rrf1.getName() << std::endl;
        b.executeForm(rrf1);
        std::cout << b.getName() << " was handed form " << scf.getName() << std::endl;
        b.signAForm(scf);
        std::cout << "Form " << scf.getName() << ":\n\tSigned status: " << scf.getSigned() << std::endl;
        std::cout << b.getName() << " is ready to execute form " << scf.getName() << std::endl;
        b.executeForm(scf);
        std::cout << b.getName() << " did what was asked so his grade goes up" << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        std::cout << "\t***********" << std::endl; 
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "\t***********" << std::endl;
    }
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