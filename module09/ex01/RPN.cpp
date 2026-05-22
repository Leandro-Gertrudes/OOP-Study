/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:28:30 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/22 16:34:46 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int	RPN(char *input){
	
	std::stringstream ss(input);
	std::string token;
	std::stack<int> stk;
	
	while(ss >> token){
		parser(token);
		
		if(std::isdigit(token[0]))
			stk.push(token[0] - '0');
		else
			operation(token, stk);
	}
	if(stk.size() > 1)
		throw std::invalid_argument("invalid input");
	return stk.top();
}

void operation(std::string token, std::stack<int> &stk){
	if(stk.size() < 2)
		throw std::invalid_argument("invalid input");

	int b = stk.top();
	stk.pop();
	int a = stk.top();
	stk.pop();
	
	int result;
	
	switch (token[0])
	{
	case '*':
		result = a * b;
		break;
	case '-':
		result = a - b;
		break;
	case '+':
		result = a + b;
		break;
	case '/':
		if(b == 0)
			throw std::invalid_argument("invalid input: division by zero");
		result = a / b;
		break;
	
	}
	stk.push(result);
}

void parser(std::string token){
	if(token.size() > 1 || (!std::isdigit(token[0]) && !isOperator(token))){
		 throw std::invalid_argument("invalid input");
	}
}

int isOperator(std::string token){
	std::string ops = "+-*/";
	return ops.find(token[0]) != std::string::npos;
}