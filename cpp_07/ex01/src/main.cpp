/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:35:20 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/17 15:05:42 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

int main (void)
{
	{
		std::cout << "*********************************" << std::endl;
		std::cout << "TEST - STRING-TAB:" <<  std::endl;
		std::string	test[] = {"IsString", "or", "not", "?"};
		
		iter<std::string, size_t, void>(test, 4, print_iter);
	}
	{
		std::cout << "*********************************" << std::endl;
		std::cout << "TEST - STRING:" <<  std::endl;
		std::string	test = "IsString";
		
		iter<const char, size_t, void>(test.c_str(), test.size(), print_iter);
	}
	{
		std::cout << "*********************************" << std::endl;
		std::cout << "TEST - CHAR:" <<  std::endl;
		char const	*test = "IsChar";
		
		iter<const char, size_t, void>(test, 6, print_iter);
	}
	{
		std::cout << "*********************************" << std::endl;
		std::cout << "TEST - INT:" <<  std::endl;
		int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		
		iter<const int, size_t, void>(tab, 10, print_iter);
	}
	{
		std::cout << "*********************************" << std::endl;
		std::cout << "TEST - FLOAT:" <<  std::endl;
		float	tab[] = {0.1f, 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f, 9.7f};
		
		iter<const float, size_t, void>(tab, 10, print_iter);
	}
	{
		std::cout << "*********************************" << std::endl;
		std::cout << "TEST - DOUBLE:" <<  std::endl;
		float	tab[] = {0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.7};
		
		iter<const float, size_t, void>(tab, 10, print_iter);
		std::cout << "*********************************" << std::endl;
	}
}
