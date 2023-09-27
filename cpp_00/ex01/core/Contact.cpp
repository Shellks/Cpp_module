/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:26:10 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/26 14:38:22 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string	Contact::_checklength(std::string str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::printcontact(void) const {
	std::cout << "firstname : " << this->_firstname << std::endl;
	std::cout << "lastname : " << this->_lastname << std::endl;
	std::cout << "nickname : " << this->_nickname << std::endl;
	std::cout << "darkest secret : " << this->_darkestsecret << std::endl;
	std::cout << "phone number : " << this->_phonenumber << std::endl;
}

void	Contact::printsearchlist(void) const {
	std::cout << "|" << std::setw(10) << this->_checklength(this->_firstname);
	std::cout << "|" << std::setw(10) << this->_checklength(this->_lastname);
	std::cout << "|" << std::setw(10) << this->_checklength(this->_nickname);
	std::cout << "|" << std::endl;
}

static std::string	trim_input(std::string str) {
	int			end;
	int			start;
	std::string	totrim = " \t";
	
	start = str.find_first_not_of(totrim);
	str = str.substr(start);
	end = str.find_last_not_of(totrim);
	str = str.substr(0, end + 1);
	return (str);
}

std::string	Contact::getinput() {
	std::string	str;
	bool		value = false;

	while (value == false) {
		std::getline(std::cin, str);
		if (std::cin.eof())
			std::exit(0);
		if (!str.empty()) {
			for (std::size_t i = 0; i < str.length(); i++)
				if (!std::isspace(str[i]) && str[i] != ' ' && str[i] != '\t')
					value = true;
			if (value == false) {
				std::cout << "Input cannot contain only space or tab, please try again" << std::endl;
				std::cout << "> ";
			}
		}
		else {
			std::cout << "Input cannot be empty, please try again" << std::endl;
			std::cout << "> ";
			std::cin.clear();
		}
	}
	str = trim_input(str);
	return (str);
}

void	Contact::initcontact(void) {
	std::cin.clear();
	std::cout << "Enter your firstname : ";
	this->_firstname = this->getinput();
	std::cout << "Enter your lastname : ";
	this->_lastname = this->getinput();
	std::cout << "Enter your nickname : ";
	this->_nickname = this->getinput();
	std::cout << "Enter your darkest secret : ";
	this->_darkestsecret = this->getinput();
	std::cout << "Enter your phonenumber : ";
	this->_phonenumber = this->getinput();
	return ;
}
