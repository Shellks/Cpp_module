/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:34:05 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/18 22:45:56 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int main()
{
	{
		std::cout << MAGENTA << "******************************" << std::endl;
		std::cout << MAGENTA << "TEST" << RESET << " - " << YELLOW << "STANDARD COMPARISON WITH VECTOR (INT)" << RESET << std::endl;
		std::cout << GREEN << "MutantStack" << MAGENTA << "  |  " << GREEN << "Vector" << RESET << std::endl;
		std::vector<int> vstack;
		MutantStack<int> mstack;
		if (mstack.empty() && vstack.empty())
			std::cout << "-> " << RED << "is empty" << MAGENTA << "  | " << RESET << "-> " << RED << "is empty" << RESET << std::endl;
		vstack.push_back(5);
		mstack.push(5);
		std::cout << "-> add " << CYAN << mstack.top() << MAGENTA << "     |" << RESET << " -> add " << CYAN << vstack.back() << RESET << std::endl;
		mstack.push(17);
		vstack.push_back(17);
		std::cout << "-> add " << CYAN << mstack.top() << MAGENTA << "    |" << RESET << " -> add " << CYAN << vstack.back() << RESET << std::endl;
		std::cout << "-> size = " << CYAN << mstack.size() << MAGENTA << "  |" << RESET << " -> size = " << CYAN << vstack.size() << RESET << std::endl;
		std::cout << "-> remove " << CYAN << mstack.top() << MAGENTA << " |" << RESET << " -> remove " << CYAN << vstack.back() << RESET << std::endl;
		mstack.pop();
		vstack.pop_back();
		std::cout << "-> size = " << CYAN << mstack.size() << MAGENTA << "  |" << RESET << " -> size = " << CYAN << vstack.size() << RESET << std::endl;
		mstack.push(0);
		vstack.push_back(0);
		mstack.push(3);
		vstack.push_back(3);
		mstack.push(5);
		vstack.push_back(5);
		mstack.push(737);
		vstack.push_back(737);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << GREEN << "Mutantstack " << MAGENTA << " |" << GREEN << " Vector " << RESET << std::endl;
		std::cout << GREEN << "content: " << MAGENTA << "    |" << GREEN << " content: " << RESET << std::endl;
		int i = 0;
		while (it != ite) {
			std::cout << "-> " << CYAN << *it << RESET << "	     "<< MAGENTA << "|" << RESET << " -> " << CYAN << vstack[i] << RESET << std::endl;
			++it;
			i++;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << MAGENTA << "******************************" << std::endl;
		std::cout << MAGENTA << "TEST" << RESET << " - " << YELLOW << "FLOAT COMPARISON" << RESET << std::endl;
		std::cout << GREEN << "MutantStack" << MAGENTA << "  |  " << GREEN << "Vector" << RESET << std::endl;
		std::vector<float> vstack;
		MutantStack<float> mstack;
		if (mstack.empty() && vstack.empty())
			std::cout << "-> " << RED << "is empty" << MAGENTA << "  | " << RESET << "-> " << RED << "is empty" << RESET << std::endl;
		vstack.push_back(5.42f);
		mstack.push(5.42f);
		std::cout << "-> add " << CYAN << mstack.top() << MAGENTA << "  |" << RESET << " -> add " << CYAN << vstack.back() << RESET << std::endl;
		mstack.push(1.4f);
		vstack.push_back(1.4f);
		std::cout << "-> add " << CYAN << mstack.top() << MAGENTA << "   |" << RESET << " -> add " << CYAN << vstack.back() << RESET << std::endl;
		std::cout << "-> size = " << CYAN << mstack.size() << MAGENTA << "  |" << RESET << " -> size = " << CYAN << vstack.size() << RESET << std::endl;
		std::cout << "-> remove " << CYAN << mstack.top() << MAGENTA << "|" << RESET << " -> remove " << CYAN << vstack.back() << RESET << std::endl;
		mstack.pop();
		vstack.pop_back();
		std::cout << "-> size = " << CYAN << mstack.size() << MAGENTA << "  |" << RESET << " -> size = " << CYAN << vstack.size() << RESET << std::endl;
		mstack.push(0.42f);
		vstack.push_back(0.42f);
		mstack.push(3.42f);
		vstack.push_back(3.42f);
		mstack.push(5.42f);
		vstack.push_back(5.42f);
		mstack.push(7.42f);
		vstack.push_back(7.42f);
		MutantStack<float>::iterator it = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();
		std::cout << GREEN << "Mutantstack " << MAGENTA << " |" << GREEN << " Vector " << RESET << std::endl;
		std::cout << GREEN << "content: " << MAGENTA << "    |" << GREEN << " content: " << RESET << std::endl;
		int i = 0;
		while (it != ite) {
			std::cout << "-> " << CYAN << *it << RESET << "	     "<< MAGENTA << "|" << RESET << " -> " << CYAN << vstack[i] << RESET << std::endl;
			++it;
			i++;
		}
		std::stack<float> s(mstack);
	}
	{
		std::cout << MAGENTA << "******************************" << std::endl;
		std::cout << MAGENTA << "TEST" << RESET << " - " << YELLOW << "STD::STRING COMPARISON" << RESET << std::endl;
		std::cout << GREEN << "MutantStack" << MAGENTA << "  |  " << GREEN << "Vector" << RESET << std::endl;
		std::vector<std::string> vstack;
		MutantStack<std::string> mstack;
		if (mstack.empty() && vstack.empty())
			std::cout << "-> " << RED << "is empty" << MAGENTA << "  | " << RESET << "-> " << RED << "is empty" << RESET << std::endl;
		mstack.push("moon");
		vstack.push_back("moon");
		std::cout << "-> add " << CYAN << mstack.top() << MAGENTA << "  |" << RESET << " -> add " << CYAN << vstack.back() << RESET << std::endl;
		mstack.push("sun");
		vstack.push_back("sun");
		std::cout << "-> add " << CYAN << mstack.top() << MAGENTA << "   |" << RESET << " -> add " << CYAN << vstack.back() << RESET << std::endl;
		std::cout << "-> size = " << CYAN << mstack.size() << MAGENTA << "  |" << RESET << " -> size = " << CYAN << vstack.size() << RESET << std::endl;
		std::cout << "-> remove " << CYAN << mstack.top() << MAGENTA << "|" << RESET << " -> remove " << CYAN << vstack.back() << RESET << std::endl;
		mstack.pop();
		vstack.pop_back();
		std::cout << "-> size = " << CYAN << mstack.size() << MAGENTA << "  |" << RESET << " -> size = " << CYAN << vstack.size() << RESET << std::endl;
		mstack.push("fire");
		vstack.push_back("fire");
		mstack.push("air");
		vstack.push_back("air");
		mstack.push("iron");
		vstack.push_back("iron");
		mstack.push("ruby");
		vstack.push_back("ruby");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		std::cout << GREEN << "Mutantstack " << MAGENTA << " |" << GREEN << " Vector " << RESET << std::endl;
		std::cout << GREEN << "content: " << MAGENTA << "    |" << GREEN << " content: " << RESET << std::endl;
		int i = 0;
		while (it != ite) {
			std::cout << "-> " << CYAN << *it << RESET << "	     "<< MAGENTA << "|" << RESET << " -> " << CYAN << vstack[i] << RESET << std::endl;
			++it;
			i++;
		}
		std::stack<std::string> s(mstack);
	}
	{
		std::cout << MAGENTA << "******************************" << std::endl;
		std::cout << MAGENTA << "TEST" << RESET << " - " << YELLOW << "CHAR COMPARISON" << RESET << std::endl;
		std::cout << GREEN << "MutantStack" << MAGENTA << "  |  " << GREEN << "Vector" << RESET << std::endl;
		std::vector<char> vstack;
		MutantStack<char> mstack;
		if (mstack.empty() && vstack.empty())
			std::cout << "-> " << RED << "is empty" << MAGENTA << "  | " << RESET << "-> " << RED << "is empty" << RESET << std::endl;
		mstack.push('a');
		vstack.push_back('a');
		std::cout << "-> add " << CYAN << mstack.top() << MAGENTA << "     |" << RESET << " -> add " << CYAN << vstack.back() << RESET << std::endl;
		mstack.push('b');
		vstack.push_back('b');
		std::cout << "-> add " << CYAN << mstack.top() << MAGENTA << "     |" << RESET << " -> add " << CYAN << vstack.back() << RESET << std::endl;
		std::cout << "-> size = " << CYAN << mstack.size() << MAGENTA << "  |" << RESET << " -> size = " << CYAN << vstack.size() << RESET << std::endl;
		std::cout << "-> remove " << CYAN << mstack.top() << MAGENTA << "  |" << RESET << " -> remove " << CYAN << vstack.back() << RESET << std::endl;
		mstack.pop();
		vstack.pop_back();
		std::cout << "-> size = " << CYAN << mstack.size() << MAGENTA << "  |" << RESET << " -> size = " << CYAN << vstack.size() << RESET << std::endl;
		mstack.push('c');
		vstack.push_back('c');
		mstack.push('d');
		vstack.push_back('d');
		mstack.push('e');
		vstack.push_back('e');
		mstack.push('f');
		vstack.push_back('f');
		MutantStack<char>::iterator it = mstack.begin();
		MutantStack<char>::iterator ite = mstack.end();
		std::cout << GREEN << "Mutantstack " << MAGENTA << " |" << GREEN << " Vector " << RESET << std::endl;
		std::cout << GREEN << "content: " << MAGENTA << "    |" << GREEN << " content: " << RESET << std::endl;
		int i = 0;
		while (it != ite) {
			std::cout << "-> " << CYAN << *it << RESET << "	     "<< MAGENTA << "|" << RESET << " -> " << CYAN << vstack[i] << RESET << std::endl;
			++it;
			i++;
		}
		std::stack<char> s(mstack);
		// std::cout << GREEN << "StackCopy " << MAGENTA << "   |" << GREEN << " Vector " << RESET << std::endl;
		// std::cout << GREEN << "content: " << MAGENTA << "    |" << GREEN << " content: " << RESET << std::endl;
		// i = 0;
		// while (!s.empty()) {
		// 	std::cout << "-> " << CYAN << s.top() << RESET << "	     "<< MAGENTA << "|" << RESET << " -> " << CYAN << vstack[i] << RESET << std::endl;
		// 	s.pop();
		// 	i++;
		// }
		std::cout << MAGENTA << "**************************" << std::endl;
	}
}
