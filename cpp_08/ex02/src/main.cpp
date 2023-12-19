/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:34:05 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/19 17:21:31 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int main()
{
	{
		std::cout << MAGENTA << "******************************" << std::endl;
		std::cout << MAGENTA << "TEST" << RESET << " - " << YELLOW << "STANDARD COMPARISON WITH VECTOR" << RESET << std::endl;
		std::cout << MAGENTA << "MutantStack  | Vector" << RESET << std::endl;
		std::vector<int> vstack;
		vstack.push_back(5);
		vstack.push_back(17);
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "-> " << CYAN << mstack.top() << RESET << "	     "<< MAGENTA << "|" << RESET << " -> " << CYAN << vstack.back() << RESET << std::endl;
		mstack.pop();
		vstack.pop_back();
		std::cout << "-> " << CYAN << mstack.size() << RESET << "	     "<< MAGENTA << "|" << RESET << " -> " << CYAN << vstack.size() << RESET << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		vstack.push_back(3);
		vstack.push_back(5);
		vstack.push_back(737);
		vstack.push_back(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		int i = 0;
		while (it != ite)
		{
			std::cout << "-> " << CYAN << *it << RESET << "	     "<< MAGENTA << "|" << RESET << " -> " << CYAN << vstack[i] << RESET << std::endl;
			++it;
			i++;
		}
		std::stack<int> s(mstack);
		std::cout << MAGENTA << "**************************" << std::endl;
	}
}