/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:49:23 by pforesti          #+#    #+#             */
/*   Updated: 2022/09/13 09:00:37 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

int	error(std::string error) {
	std::cout << "replace: error: " << error << std::endl;
	return (1);
}

int	replace(std::string path, std::string s1, std::string s2) {

	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		buf;
	int	y = 0;
	int	i = 0;

	if (s1 == "" || s2 == "")
		return(error("one of the two strings is empty"));

	ifs.open(path, std::ifstream::in);
	if ((ifs.rdstate() & std::ifstream::failbit))
		return (error("error opening file named \"" + path + "\""));
	
	buf.assign(std::istreambuf_iterator<char>(ifs),
			std::istreambuf_iterator<char>());

	std::transform(path.begin(), path.end(), path.begin(), ::toupper);
	ofs.open(path + ".replace", std::ofstream::out);

	while (i < (int)buf.length())
	{
		y = buf.find(s1, i);
		if (y == -1)
			break ; 
		buf.erase(y, s1.length());
		buf.insert(y, s2);
		i = y + 1;
	}
	ofs << buf;

	ifs.close();
	ofs.close();
	return (0);
}

int	main(int ac, char *argv[])
{
	if (ac != 4)
		return(error("wrong number of arguments"));
	return(replace(argv[1], argv[2], argv[3]));
}
