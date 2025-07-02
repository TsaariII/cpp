/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:53:13 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/02 13:27:35 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

struct Data
{
    int id;
    std::string name;
};

class Serializer
{
    public:
        static uintptr_t serializer(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
      Serializer();
      Serializer(const Serializer& ref);
      ~Serializer();
      Serializer& operator=(const Serializer& copy);
      
};