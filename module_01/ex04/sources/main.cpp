/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:06:37 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/14 16:33:02 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "To use this enter " << argv[0] << " <filename> <s1> <s2>" << std::endl;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[2];
	if (s1.empty())
	{
		std::cerr << "The s1 cannot be empty" << std::endl;
	}
}
