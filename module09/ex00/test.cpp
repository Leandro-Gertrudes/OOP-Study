/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:28:17 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/06 16:34:03 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<std::string, float> prices;

    // inserir alguns preços
    prices["2009-01-01"] = 0.0;
    prices["2011-01-03"] = 0.3;
    prices["2012-01-11"] = 7.1;
    prices["2013-05-01"] = 120.0;
    prices["2014-01-01"] = 800.0;

    // iterar e imprimir tudo
    std::cout << "--- todos os precos ---" << std::endl;
    std::map<std::string, float>::iterator it;
    for(it = prices.begin(); it != prices.end(); it++)
        std::cout << it->first << " => " << it->second << std::endl;

    // procurar data exata
    std::cout << "\n--- procura exata ---" << std::endl;
    std::string date = "2012-01-11";
    if(prices.count(date))
        std::cout << date << " encontrado: " << prices[date] << std::endl;

    // procurar data mais proxima anterior
    std::cout << "\n--- data mais proxima anterior ---" << std::endl;
    std::string search = "2012-06-15"; // nao existe no map
    it = prices.lower_bound(search);

    if(it == prices.begin())
        std::cout << "Error: data anterior a tudo no DB" << std::endl;
    else {
        --it;
        std::cout << search << " nao existe, usando: " << it->first
                  << " => " << it->second << std::endl;
    }

    return 0;
}