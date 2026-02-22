/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:29:40 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/29 13:58:31 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void ft_erase_insert(std::string *str,
	std::string s1, std::string s2);

std::string ft_getFileName(char *file);

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << ERROR_NUM_PARAM << std::endl;
		return (1);
	}

	std::ifstream file(argv[1], std::ios::in);
	std::ofstream fileReplace(ft_getFileName(argv[1]).c_str(), std::ios::out);
	std::string str;

	if(!file.is_open()){
		std::cerr << ERROR_NOT_FOUND << std::endl;
		return(1);
	}

	while(std::getline(file, str ))
	{
		ft_erase_insert(&str, argv[2], argv[3]);
		fileReplace << str << std::endl;
	}
	file.close();
}

void ft_erase_insert(std::string *str,
	std::string s1, std::string s2)
{		
	size_t i;
	do
	{
		i = str->find(s1);
		if(i != std::string::npos)
		{
			str->erase(i, s1.length());
			str->insert(i, s2);
		}
	} while (i != std::string::npos);
}

std::string ft_getFileName(char *file)
{
	std::string str = file;

	str.append(".replace");

	return str;
}
