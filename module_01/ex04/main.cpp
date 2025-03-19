/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:06:37 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/19 10:23:46 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void changeStr(const std::string filename, const std::string s1, const std::string s2)
{
	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "Cannot open " << filename << std::endl;
		return ;
	}
	std::string outputName = filename + ".replace";
	std::ofstream outputFile(outputName);
	if (!outputFile)
	{
		std::cerr << "Cannot create file" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string newLine;
		size_t indx = 0;
		while ((indx = line.find(s1, indx)) != std::string::npos)
		{
			newLine += line.substr(0, indx) + s2;
			line = line.substr(indx + s1.length());
			indx += s2.length();
		}
		newLine += line;
		outputFile << newLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "To use this enter " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "The s1 cannot be empty" << std::endl;
		return 1;
	}
	changeStr(filename, s1, s2);
	return 0;
}
