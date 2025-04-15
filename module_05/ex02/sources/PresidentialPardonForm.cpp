/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:05:51 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 17:12:11 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &copy) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {}