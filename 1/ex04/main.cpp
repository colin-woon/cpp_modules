/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:23:42 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/10 00:48:18 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::string contents;
	std::string new_contents;

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

	std::string s1 = av[2];
	std::string s2 = av[3];

	if (infile)
	{
		// Get the file size
		infile.seekg(0, std::ios::end);
		std::streamsize size = infile.tellg();
		infile.seekg(0, std::ios::beg);

		// Resize string and read the file
		contents.resize(size);
		infile.read(&contents[0], size);
		infile.close();

		int last_pos = 0;
		for (size_t i = 0; i < contents.length(); i++)
		{
			std::size_t pos;

			pos = contents.find(s1.c_str(), i);
			std::cout << pos << std::endl;
			std::cout << i << std::endl;
			std::cout << last_pos << std::endl;
			if (pos != std::string::npos)
			{
				new_contents += contents.substr(i, pos - i);
				new_contents.append(s2.c_str());
				i = pos + s2.length();
				// i += s2.length();
				// if (s2.length() == 0)
				i += s1.length();
				last_pos = i;
			}
			if (i + 1 == contents.length())
			{
				new_contents += contents.substr(last_pos, i - last_pos);
			}
			std::cout << i << std::endl;
			std::cout << last_pos << std::endl;
			std::cout << new_contents << std::endl
					  << std::endl;
		}
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
