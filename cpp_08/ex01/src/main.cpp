/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:18:07 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/19 16:31:37 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main (void)
{
	{
		std::cout << MAGENTA << "TEST" << RESET << " -> " << YELLOW << "SPAN" << RESET << std::endl;
		try 
		{
			int size = 100;
			Span	test(size);
			int		tab[size];
			std::srand(std::time(NULL));

			for (int i = 0; i < size; i++)
				tab[i] = std::rand() % 10;
			test.addNumber(tab, (size - 1));
			std::cout << " -" << GREEN << "ShortestSpan" << RESET << " is '" << CYAN << test.shortestSpan() << RESET << "'" << std::endl;
			std::cout << " -" << GREEN << "LongestSpan" << RESET << " is '" << CYAN << test.longestSpan() << RESET << "'" << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "*********************************" << RESET << std::endl;
	}
	{
		std::cout << MAGENTA << "TEST" << RESET << " -> " << YELLOW << "EXCEPTION" << RESET << std::endl;
		try 
		{
			Span	test(10);
			
			for (int i = 0; i < 11; i++)
			{
				test.addNumber(i);
				std::cout << " -" << GREEN << "Adding" << RESET << " '" << CYAN << i << RESET << "' to " << YELLOW << "container" << RESET << std::endl;
			}
		}
		catch (std::exception const &e)
		{
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}
		try 
		{
			Span	test(10);
			int		tab[100];
			std::srand(std::time(NULL));

			for (int i = 0; i < 100; i++)
				tab[i] = std::rand() % 100;
			test.addNumber(tab, 10);
			std::cout << " -" << GREEN << "ShortestSpan" << RESET << " is '" << CYAN << test.shortestSpan() << RESET << "'" << std::endl;
			std::cout << " -" << GREEN << "LongestSpan" << RESET << " is '" << CYAN << test.longestSpan() << RESET << "'" << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "*********************************" << RESET << std::endl;
	}
	{
		std::cout << MAGENTA << "TEST" << RESET << " -> " << YELLOW << "STANDARD FILL" << RESET << std::endl;
		try 
		{
			Span sp = Span(5);
			sp.addNumber(6);
			std::cout << " -" << GREEN << "Adding" << RESET << " '" << CYAN << 6 << RESET << "' to " << YELLOW << "container" << RESET << std::endl;
			sp.addNumber(3);
			std::cout << " -" << GREEN << "Adding" << RESET << " '" << CYAN << 3 << RESET << "' to " << YELLOW << "container" << RESET << std::endl;
			sp.addNumber(-17);
			std::cout << " -" << GREEN << "Adding" << RESET << " '" << CYAN << 17 << RESET << "' to " << YELLOW << "container" << RESET << std::endl;
			sp.addNumber(9);
			std::cout << " -" << GREEN << "Adding" << RESET << " '" << CYAN << 9 << RESET << "' to " << YELLOW << "container" << RESET << std::endl;
			sp.addNumber(11);
			std::cout << " -" << GREEN << "Adding" << RESET << " '" << CYAN << 11 << RESET << "' to " << YELLOW << "container" << RESET << std::endl;
			std::cout << " -" << GREEN << "ShortestSpan" << RESET << " is '" << CYAN << sp.shortestSpan() << RESET << "'" << std::endl;
			std::cout << " -" << GREEN << "LongestSpan" << RESET << " is '" << CYAN << sp.longestSpan() << RESET << "'" << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "*********************************" << RESET << std::endl;
	}
}