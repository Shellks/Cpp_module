/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileName.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:09:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/29 15:56:00 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Filename.hpp"

Filename::Filename(std::string infile, std::string s1, std::string s2) \
: _infile(infile), _search(s1), _replace(s2), _outfile(infile += ".replace")
{
	return ;
}

Filename::~Filename(void)
{
	return ;
}

bool	Filename::_WriteFilename(void)
{
	std::ofstream	ofs(this->_outfile.c_str());

	if (!ofs.is_open() || ofs.fail()) {
		std::cout << "Error occurs with output file" << std::endl;
		return false;
	}
	ofs << this->_buffer;
	ofs.close();
	return true;
}

bool	Filename::_Replace(void)
{
	if (this->_search.empty()) {
		std::cout << "Search arguments cannot be empty" << std::endl;
		return false;
	}
	std::size_t	pos = this->_buffer.find(this->_search);
	while (pos != std::string::npos) {
		this->_buffer.erase(pos, this->_search.length());
		this->_buffer.insert(pos, this->_replace);
		pos = this->_buffer.find(this->_search);
	}
	return true;
}

int	Filename::ReadFilename(void)
{
	std::ifstream	ifs(this->_infile.c_str());
	
	if (!ifs.is_open() || ifs.fail()) {
		std::cout << "input files cannot be read" << std::endl;
		return ERR_READ;
	}
	if (std::getline(ifs, this->_buffer, '\0')) {
		if (this->_Replace() == false) {
			ifs.close();
			return ERR_PARAM;
		}
		if (this->_WriteFilename() == false) {
			ifs.close();
			return ERR_WRITE;
		}
		ifs.close();
	}
	else {
		ifs.close();
		std::cout << "Infile is empty !" << std::endl;
		return ERR_READ;
	}
	return SUCCES;
}

