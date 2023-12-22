/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:45 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/21 22:57:18 by acarlott         ###   ########lyon.fr   */
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

typedef typename std::map<std::string, float> DataBase;
typedef typename DataBase::iterator iterator;

class BitcoinExchange
{
private:
	DataBase _dataCsv;
	DataBase _dataUser;
	const char	* _fileUser;
	const char	* _fileCsv;
	
	void	_parseDbCsv(void);
	void	_parseDbUser(void);

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
};



#endif