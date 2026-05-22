/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:52:45 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/22 16:54:15 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <exception>
#include <cctype>
#include <ctime>
#include <climits>
#include <cstdlib>

class PmergeMe{
	private:
		std::vector<int> vec;
		std::deque<int>  deq;

		double vecTime;
		double deqTime;

		// vector
		void sortVector();
		void mergeInsertVector(std::vector<int> &v);
		std::vector<int> jacobsthalOrderVector(int n);

		// deque
		void sortDeque();
		void mergeInsertDeque(std::deque<int> &d);
		std::deque<int> jacobsthalOrderDeque(int n);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void parseInput(int argc, char **argv);
		void run();
		void printBefore();
		void printAfter();
		void printTimes();
};

// utils
bool isValidNumber(const std::string &str);