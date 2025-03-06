/***************************************************************************              */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filestreams.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:07:16 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/06 15:11:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream infile("filestreams.cpp");
	std::ofstream outfile("outfile.txt");
	std::string line;

	// this line, will move the buffer too, and ends at any white space, so youll see it doesnt print */
	infile >> line;
	std::cout << line << std::endl;

	/* this line, will move the buffer */
	outfile << infile.rdbuf();

	std::cout << outfile.tellp();
	outfile.close();
	infile.close();
}
