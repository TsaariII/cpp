/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:55:27 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/10 11:43:27 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}
std::string Contact::getFirstName() { return (_FirstName); }

std::string Contact::getLastName() { return (_LastName); }

std::string Contact::getNickName() { return (_NickName); }

std::string Contact::getNumber() { return (_Number); }

std::string Contact::getSecret() { return (_Secret); }

void Contact::setFirstName(std::string info) { _FirstName = info; }

void Contact::setLastName(std::string info) { _LastName = info; }

void Contact::setNickName(std::string info) { _NickName = info; }

void Contact::setNumber(std::string info) { _Number = info; }

void Contact::setSecret(std::string info) { _Secret = info; }
