/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:26:16 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/09 15:41:32 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

PhoneBook::PhoneBook(void) : _index(0) {
	this->_introduction();
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

int	PhoneBook::getindex(void) const
{
	return PhoneBook::_index;
}

void	PhoneBook::_getcontact(void) const
{
	bool	flag = false;
	std::string	str_index;
	int			index;

	std::cin.clear();
	std::cout << std::endl << "Choose an index number for see complete information about this contact : " << std::endl;
	std::cout << "> ";
	std::cin >> str_index;
	while(flag == false) {
		if (std::cin.eof())
			std::exit(0);
		index = std::atoi(str_index.c_str());
		if (str_index.find_first_not_of("0123456789") == std::string::npos && std::cin.good() && index > 0 && index <= this->getindex()) {
			flag = true;
			this->_contacts[index - 1].printcontact();
			std::cin.ignore();
		}
		else {
			std::cin.clear();
			std::cout << "wrong index, please refer to the index in the table above and retry" << std::endl;
			std::cout << "> ";
			std::cin >> str_index;
		}
	}
}

void	PhoneBook::searchcontact(void) const
{
	if (this->_index != 0) {
		std::cout << "|" << std::setw(10) << "index";
		std::cout << "|" << std::setw(10) << "firstname";
		std::cout << "|" << std::setw(10) << "lastname";
		std::cout << "|" << std::setw(10) << "nickname";
		std::cout << "|" << std::endl;
		for (int i = 1; i < _index + 1; i++) {
			std::cout << "|" << std::setw(10) << i;
			this->_contacts[i - 1].printsearchlist();
		}
		this->_getcontact();
	}
	else
		std::cout << "no contact saved, add a new one with 'ADD'" << std::endl;
}

void		PhoneBook::_replacecontact(void)
{
	for (int i = 0; i != 7; i++)
		this->_contacts[i] = this->_contacts[i + 1];
}

void	PhoneBook::addcontact(void)
{
	if (this->_index < 8) {
		this->_contacts[_index].initcontact();
		this->_index += 1;
	}
	else {
		PhoneBook::_replacecontact();
		this->_index -= 1;
		this->_contacts[_index].initcontact();
		this->_index += 1;
	}
	std::cout << std::endl << "Contact successfully added !" << std::endl;
}

void	PhoneBook::_introduction(void) const
{
	std::cout << std::endl << "          Welcome to your awesome PhoneBook !" << std::endl << std::endl;
	std::cout << "---NOTICE---" << std::endl;
	std::cout << "'ADD' to add a contact." << std::endl;
	std::cout << "'SEARCH' to search a contact." << std::endl;
	std::cout << "'EXIT' to close your PhoneBook." << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << std::endl;
}
