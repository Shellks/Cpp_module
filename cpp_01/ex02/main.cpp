/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:34:44 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/28 17:46:53 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	ptrstr = &str;
	std::string&	refstr = str;

	std::cout << "str on stack adress: " << &str << std::endl;
	std::cout << "ptr of str adress: " << ptrstr << std::endl;
	std::cout << "ref of str adress: " << &refstr << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "str on stack value: " << str << std::endl;
	std::cout << "ptr of str value: " << *ptrstr << std::endl;
	std::cout << "ref of str value: " << refstr << std::endl;
	return 0;
}