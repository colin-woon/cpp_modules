/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:23:42 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/10 17:22:42 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./ex04 [filename] [s1] [s2]" << std::endl;
		return (1);
	}

	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}

	if (av[2][0] == '\0')
	{
		std::cerr << "Error: s1 is empty, string to replace unspecified" << std::endl;
		return (1);
	}

	if (infile)
	{
		std::string contents;
		std::string new_contents;
		std::string s1 = av[2];
		std::string s2 = av[3];
		int last_pos = 0;

		infile.seekg(0, std::ios::end);
		std::streamsize size = infile.tellg();
		infile.seekg(0, std::ios::beg);
		contents.resize(size);
		infile.read(&contents[0], size);
		infile.close();
		for (size_t i = 0; i < contents.length(); i++)
		{
			std::size_t pos;

			pos = contents.find(s1.c_str(), i);
			if (pos != std::string::npos)
			{
				new_contents += contents.substr(i, pos - i);
				new_contents.append(s2.c_str());
				last_pos = pos + s1.length() - 1;
				i = last_pos;
			}
			if (i + 1 == contents.length())
			{
				new_contents += contents.substr(last_pos + 1, i - last_pos);
			}
		}
		// std::cout << new_contents << std::endl;
		std::ofstream outfile("replacement.txt");
		if (outfile.is_open())
		{
			outfile << new_contents;
			outfile.close();
		}
		else
		{
			std::cerr << "Error: Could not create output file" << std::endl;
			return 1;
		}
	}
	return 0;
}
