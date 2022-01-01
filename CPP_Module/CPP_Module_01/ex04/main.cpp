/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:48:17 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/01 19:51:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	check_exception(int argc, char *argv[])
{
	std::string str;

	if (argc != 4)
	{
		std::cout << "invalid number of arguments" << std::endl;
		return (1);
	}

	for (int i = 1 ; i < argc ; i++)
	{
		str = std::string(argv[i]);
		if (str.size() == 0)
		{
			std::cout << "s1 or s2 is an empty string" << std::endl;
			return (1);
		}
	}
	return (0);
}

int	read_file(std::string &filename, std::string &result)
{
	std::ifstream	ifs;
	std::string		input = "";

	ifs.open(filename);
	if (!ifs.is_open())
	{
		std::cout << "file read error" << std::endl;
		return (1);
	}
	
	while (getline(ifs, input))
	{
		result.append(input);
		result.append("\n");
	}
	ifs.close();
	return (0);
}

int	write_file(std::string filename, std::string &result)
{
	std::ofstream ofs;

	filename.append(".replace");
	ofs.open(filename);
	if (!ofs.is_open())
	{
		std::cout << "file write err" << std::endl;
		return (1);
	}
	ofs << result;
	ofs.close();
	return (0);
}

int main(int argc, char *argv[])
{
	std::string filename, s1, s2;
	std::string result = "";
	int pos = 0;

	if (check_exception(argc, argv))
		return (1);

	filename = std::string(argv[1]);
	s1 = std::string(argv[2]);
	s2 = std::string(argv[3]);

	if (read_file(filename, result))
		return (1);

	while (1)
	{
		pos = result.find(s1, pos);
		if (pos == -1)
			break;
		result.erase(pos ,s1.size());
		result.insert(pos, s2);
		pos++;
	}

	if (write_file(filename, result))
		return (1);
	return (0);
}
