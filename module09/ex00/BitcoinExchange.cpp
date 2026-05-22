/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:50:17 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/22 16:06:20 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	this->db = this->loadCSV();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
	this->db = other.db;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if(this != &other)
		this->db = other.db;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){

}


///////////////////////////////////////////////////////

std::map<std::string, float> BitcoinExchange::loadCSV()
{
	std::map<std::string, float>db;
	std::string line;
	std::ifstream file("data.csv");
	std::string date;
	std::string valueStr;

	if(!file.is_open())
		throw std::runtime_error("Error: could not open data base file.");
	
	std::getline(file, line);



	while(std::getline(file, line)){
		
		size_t pos = line.find(',');

		date = line.substr(0, pos);
		valueStr = line.substr(pos + 1);
		
		float price = std::strtof(valueStr.c_str(), NULL);

		db[date] = price;
	}

	return db;
}


void BitcoinExchange::processExchange(std::string filename){
	std::ifstream file(filename.c_str());
	std::string line;

	if(!file.is_open())
		throw std::runtime_error("Error: could not open user file.");
	
	std::getline(file, line);
	
	if(line != "date | value")
		throw std::runtime_error("Error: the file must inicialized by \" data | value \"");

	while(std::getline(file, line)){
		try{
			find_print_value(db, line);
		} catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
}


///////	utils


bool BitcoinExchange::isValidDate(const std::string &date)
{
    if(date.size() != 10)
        return false;
    if(date[4] != '-' || date[7] != '-')
        return false;

    for(int i = 0; i < 10; i++)
    {
        if(i == 4 || i == 7)
            continue;
        if(!std::isdigit(date[i]))
            return false;
    }

    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if(month < 1 || month > 12)
        return false;
    if(day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &str)
{
    int dots = 0;
    size_t i = 0;

    if(str[0] == '+')
        i = 1;
	else if(str[0] == '-')
        throw std::runtime_error("Error: not a positive number.");

    for(; i < str.size(); i++)
    {
        if(str[i] == '.')
        {
            dots++;
            if(dots > 1)
                return false;
        }
        else if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}

std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if(start == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

void BitcoinExchange::find_print_value(std::map<std::string, float> &db, std::string line){
	
	size_t pos = line.find('|');
	
	
	if(pos == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line); 

	std::string date = trim(line.substr(0, pos));
	std::string valueStr = trim(line.substr(pos + 1));
	
	if(!isValidValue(valueStr) || !isValidDate(date))
    	throw std::runtime_error("Error: bad input => " + line);
	
	float value = std::strtof(valueStr.c_str(), NULL);

	if(value < 0)
    throw std::runtime_error("Error: not a positive number.");
		if(value > 1000)
    throw std::runtime_error("Error: too large a number.");
	
	std::map<std::string, float>::iterator it;
   	it = db.lower_bound(date);

	if(it == db.begin())
    	throw std::runtime_error("Error: bad input => " + date);
	if(it->first != date)
		--it;
	
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}