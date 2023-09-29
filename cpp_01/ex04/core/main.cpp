/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:02:18 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/29 13:10:24 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Filename.hpp"

int	main(int argc, char **argv)
{
	int	status;
	
	if (argc != 4) {
		std::cout << "wrong number of parameters, three expected !" << std::endl;
		return ERR_PARAM;
	}
	Filename	Filename(argv[1], argv[2], argv[3]);
	
	status = Filename.ReadFilename();
	switch (status) {
		case ERR_PARAM:
			return ERR_PARAM;
		case ERR_READ:
			return ERR_READ;
		case ERR_WRITE:
			return ERR_WRITE;
	}
	return SUCCES;
}