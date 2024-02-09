/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:45 by acarlott          #+#    #+#             */
/*   Updated: 2024/02/09 12:27:34 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#define RESET "\033[0m"
#define RED "\033[31m"

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

typedef std::map<std::string, float> DataBase;
typedef DataBase::iterator iterator;
class BitcoinExchange
{
	private:
		DataBase _data;
		
		bool		_isValidValue(std::string const &value);
		bool		_isValidDate(std::string const &date);
		bool		_isValidInput(std::string const &date, std::string const &amount);
		std::string	_trimParser(std::string toTrim);
		void		_parseDbCsv(const char *data);
		void		_parseDbUser(const char *file);
		void		_printBtcValue(std::string const date, std::string const amount);
	
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		
		BitcoinExchange &operator=(BitcoinExchange const &src);
	
		void	btcParser(char *file, char *data);
	
		class BadFileException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};


#endif
