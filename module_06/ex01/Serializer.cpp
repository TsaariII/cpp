/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:00:50 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/02 13:45:56 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdint>

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& ref) { static_cast<void>(ref); }

Serializer::~Serializer() {}

Serializer& Serializer::operator=(const Serializer& ref) { static_cast<void>(ref); return *this; }

uintptr_t Serializer::serializer(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }
