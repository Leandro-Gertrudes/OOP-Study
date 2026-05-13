/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:38:27 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/08 20:59:32 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "exception"
#include <cstdlib>



class BitcoinExchange{
	private:
		std::map<std::string, float> db;

		void find_print_value(std::map<std::string, float> &db, std::string line);
		bool isValidDate(const std::string &date);
		bool isValidValue(const std::string &str);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		
		std::map<std::string, float> loadCSV();
		void processExchange(std::string filename);

};