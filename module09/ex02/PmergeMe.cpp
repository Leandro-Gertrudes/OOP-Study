/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:52:42 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/13 16:54:17 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
	this->vecTime = 0;
	this->deqTime = 0;
}

PmergeMe::PmergeMe(const PmergeMe &other){
	this->vec = other.vec;
	this->deq = other.deq;
	this->vecTime = other.vecTime;
	this->deqTime = other.deqTime;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
	if(this != &other){
		this->vec = other.vec;
		this->deq = other.deq;
		this->vecTime = other.vecTime;
		this->deqTime = other.deqTime;
	}
	return *this;
}

PmergeMe::~PmergeMe(){

}


///////////////////////////////////////////////////////


void PmergeMe::parseInput(int argc, char **argv){
	if(argc < 2)
		throw std::invalid_argument("Error");

	for(int i = 1; i < argc; i++){
		std::string str = argv[i];

		if(!isValidNumber(str))
			throw std::invalid_argument("Error");

		long n = std::strtol(str.c_str(), NULL, 10);

		if(n < 0 || n > INT_MAX)
			throw std::invalid_argument("Error");

		this->vec.push_back(static_cast<int>(n));
		this->deq.push_back(static_cast<int>(n));
	}
}


void PmergeMe::run(){
	this->sortVector();
	this->sortDeque();
}


///////	vector


void PmergeMe::sortVector(){
	std::clock_t start = std::clock();

	mergeInsertVector(this->vec);

	std::clock_t end = std::clock();
	this->vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;
}


void PmergeMe::mergeInsertVector(std::vector<int> &v){
	int size = v.size();

	if(size < 2)
		return;

	// 1. fazer pares e ordenar cada par (maior, menor)
	std::vector<std::pair<int, int> > pairs;
	int hasStraggler = 0;
	int straggler = 0;

	for(int i = 0; i + 1 < size; i += 2){
		int a = v[i];
		int b = v[i + 1];
		if(a < b){
			int tmp = a;
			a = b;
			b = tmp;
		}
		pairs.push_back(std::make_pair(a, b));
	}
	if(size % 2 != 0){
		hasStraggler = 1;
		straggler = v[size - 1];
	}

	// 2. ordenar recursivamente os maiores
	std::vector<int> mainChain;
	for(size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);

	mergeInsertVector(mainChain);

	// 3. reordenar pares de acordo com main chain
	std::vector<std::pair<int, int> > sortedPairs;
	for(size_t i = 0; i < mainChain.size(); i++){
		for(size_t j = 0; j < pairs.size(); j++){
			if(pairs[j].first == mainChain[i]){
				sortedPairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	// 4. criar pend (menores) na mesma ordem dos pares
	std::vector<int> pend;
	for(size_t i = 0; i < sortedPairs.size(); i++)
		pend.push_back(sortedPairs[i].second);

	// 5. inserir o primeiro menor no inicio da main chain
	if(!pend.empty()){
		mainChain.insert(mainChain.begin(), pend[0]);
	}

	// 6. inserir o resto usando a ordem de Jacobsthal
	std::vector<int> order = jacobsthalOrderVector(pend.size());

	for(size_t i = 0; i < order.size(); i++){
		int idx = order[i];
		if(idx >= (int)pend.size())
			continue;

		int value = pend[idx];

		// limitar busca ao seu "parceiro" na main chain
		int limit = idx + i + 1;
		if(limit > (int)mainChain.size())
			limit = mainChain.size();

		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + limit, value);
		mainChain.insert(pos, value);
	}

	if(hasStraggler){
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	v = mainChain;
}


std::vector<int> PmergeMe::jacobsthalOrderVector(int n){
	std::vector<int> order;

	if(n <= 1)
		return order;

	// sequencia de Jacobsthal: J(0)=0, J(1)=1, J(k) = J(k-1) + 2*J(k-2)
	// 0, 1, 1, 3, 5, 11, 21, 43...
	std::vector<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	while(jacob.back() < n){
		int next = jacob.back() + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	// gerar ordem de insercao: comecar do indice 1 (ja inserimos pend[0])
	std::vector<int> inserted;
	inserted.push_back(0);

	for(size_t k = 0; k < jacob.size(); k++){
		int j = jacob[k];
		if(j >= n)
			j = n - 1;

		// inserir de j ate o anterior nao inserido, em ordem decrescente
		int prev = (k == 0) ? 0 : jacob[k - 1];

		for(int idx = j; idx > prev; idx--){
			if(idx < n){
				order.push_back(idx);
				inserted.push_back(idx);
			}
		}
		if(j == n - 1)
			break;
	}

	return order;
}


///////	deque


void PmergeMe::sortDeque(){
	std::clock_t start = std::clock();

	mergeInsertDeque(this->deq);

	std::clock_t end = std::clock();
	this->deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;
}


void PmergeMe::mergeInsertDeque(std::deque<int> &d){
	int size = d.size();

	if(size < 2)
		return;

	std::deque<std::pair<int, int> > pairs;
	int hasStraggler = 0;
	int straggler = 0;

	for(int i = 0; i + 1 < size; i += 2){
		int a = d[i];
		int b = d[i + 1];
		if(a < b){
			int tmp = a;
			a = b;
			b = tmp;
		}
		pairs.push_back(std::make_pair(a, b));
	}
	if(size % 2 != 0){
		hasStraggler = 1;
		straggler = d[size - 1];
	}

	std::deque<int> mainChain;
	for(size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);

	mergeInsertDeque(mainChain);

	std::deque<std::pair<int, int> > sortedPairs;
	for(size_t i = 0; i < mainChain.size(); i++){
		for(size_t j = 0; j < pairs.size(); j++){
			if(pairs[j].first == mainChain[i]){
				sortedPairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	std::deque<int> pend;
	for(size_t i = 0; i < sortedPairs.size(); i++)
		pend.push_back(sortedPairs[i].second);

	if(!pend.empty()){
		mainChain.insert(mainChain.begin(), pend[0]);
	}

	std::deque<int> order = jacobsthalOrderDeque(pend.size());

	for(size_t i = 0; i < order.size(); i++){
		int idx = order[i];
		if(idx >= (int)pend.size())
			continue;

		int value = pend[idx];

		int limit = idx + i + 1;
		if(limit > (int)mainChain.size())
			limit = mainChain.size();

		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + limit, value);
		mainChain.insert(pos, value);
	}

	if(hasStraggler){
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	d = mainChain;
}


std::deque<int> PmergeMe::jacobsthalOrderDeque(int n){
	std::deque<int> order;

	if(n <= 1)
		return order;

	std::deque<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	while(jacob.back() < n){
		int next = jacob.back() + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	std::deque<int> inserted;
	inserted.push_back(0);

	for(size_t k = 0; k < jacob.size(); k++){
		int j = jacob[k];
		if(j >= n)
			j = n - 1;

		int prev = (k == 0) ? 0 : jacob[k - 1];

		for(int idx = j; idx > prev; idx--){
			if(idx < n){
				order.push_back(idx);
				inserted.push_back(idx);
			}
		}
		if(j == n - 1)
			break;
	}

	return order;
}


///////	prints


void PmergeMe::printBefore(){
	std::cout << "Before: ";
	for(size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;
}


void PmergeMe::printAfter(){
	std::cout << "After:  ";
	for(size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;
}


void PmergeMe::printTimes(){
	std::cout << "Time to process a range of " << this->vec.size()
			  << " elements with std::vector : " << this->vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << this->deq.size()
			  << " elements with std::deque  : " << this->deqTime << " us" << std::endl;
}


///////	utils


bool isValidNumber(const std::string &str){
	if(str.empty())
		return false;

	size_t i = 0;
	if(str[0] == '+')
		i = 1;

	if(i == str.size())
		return false;

	for(; i < str.size(); i++){
		if(!std::isdigit(str[i]))
			return false;
	}
	return true;
}