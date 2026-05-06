/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:29:04 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/06 15:12:52 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <exception>
#include <cctype>

int	RPN(char *input);

void operation(std::string token, std::stack<int> &stk);

// parser
void parser(std::string token);
int isOperator(std::string token);