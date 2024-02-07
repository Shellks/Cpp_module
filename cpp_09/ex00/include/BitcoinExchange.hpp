/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:45 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/07 12:03:59 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cfloat>

typedef std::map<std::string, float> DataBase;
typedef DataBase::iterator iterator;
#define  BADINPUT_MSG std::cout << "Error: bad input => " << date << " | " << amount << std::endl;
class BitcoinExchange
{
	private:
		DataBase _data;
		
		bool		_isValidInput(std::string const &date, std::string const &amount);
		std::string	_trimParser(std::string toTrim);
		void		_parseDbCsv(void);
		void		_parseDbUser(const char *file);
		void		_printBtcValue(std::string const date, std::string const amount);
	
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		
		BitcoinExchange &operator=(BitcoinExchange const &src);
	
		void	btcParser(char *file);
	
		class FileNotExistException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class EmptyFileException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class BadFileException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};



#endif
