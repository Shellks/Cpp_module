/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filename.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:06:01 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/29 15:53:56 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FILENAME_HPP
# define FILENAME_HPP

# include <iostream>
# include <fstream>

# define SUCCES 0
# define ERR_PARAM 1
# define ERR_READ 2
# define ERR_WRITE 3

class Filename
{
	private :
		std::string	_infile;
		std::string	_search;
		std::string	_replace;
		std::string	_outfile;
		std::string	_buffer;

		bool	_WriteFilename(void);
		bool	_Replace(void);
		
	public :
	
		Filename(std::string infile, std::string s1, std::string s2);
		~Filename(void);

		int		ReadFilename(void);

};

#endif