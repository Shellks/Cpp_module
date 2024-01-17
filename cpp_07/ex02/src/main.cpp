/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:02:27 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/17 15:47:56 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

int	main(void)
{
	{
		try {
			int * a = new int();
			
			std::cout << *a << std::endl;
			delete a;
		}
		catch ( std::exception const &e)
		{
			std::cout << "- " << RED << "Error" << RESET << ": " << RED << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << MAGENTA << "******************" <<  RESET << std::endl;
		std::cout << MAGENTA << "TEST" << RESET << " - " << YELLOW << "COPY" << RESET << std::endl;
		try 
		{
			Array<int>	first_array(12);

			std::cout << YELLOW << " array size" << RESET << " -> " << CYAN << first_array.size() << RESET << std::endl;
			first_array[0] = 42;
			Array<int> second_array(first_array);
			first_array[0] = 21;
			Array<int> third_array = second_array;
			second_array[0] = 84;
			std::cout << " - " << CYAN << "First array" << YELLOW << "[0]" << RESET << " -> " << CYAN << first_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Second array" << YELLOW << "[0]" << RESET << " -> " << CYAN << second_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Third array" << YELLOW << "[0]" << RESET << " -> " << CYAN << third_array[0] << RESET << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << "- " << RED << "Error" << RESET << ": " << RED << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "******************" <<  RESET << std::endl;
	}
	{
		std::cout << MAGENTA << "TEST" << RESET << " - " << YELLOW << "Exception" << RESET << std::endl;
		try 
		{
			Array<int>	first_array;
			
			std::cout << YELLOW << " array size" << RESET << " -> " << CYAN << first_array.size() << RESET << std::endl;
			first_array[0] = 42;
		}
		catch (std::exception const &e)
		{
			std::cout << "- " << RED << "Error" << RESET << ": " << RED << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "******************" <<  RESET << std::endl;
	}
	{
		std::cout << MAGENTA << "TEST" << RESET << " - " << YELLOW << "OTHER TYPES" << RESET << std::endl;
		std::cout << MAGENTA << "-----------------------------" << RESET << std::endl;
		std::cout << YELLOW << "FLOAT" << RESET << std::endl;
		try 
		{
			Array<float>	first_array(5);

			std::cout << YELLOW << " array size" << RESET << " -> " << CYAN << first_array.size() << RESET << std::endl;
			first_array[0] = 42.4f;
			Array<float> second_array(first_array);
			first_array[0] = 21.4f;
			Array<float> third_array = second_array;
			second_array[0] = 84.4f;
			std::cout << " - " << CYAN << "First array" << YELLOW << "[0]" << RESET << " -> " << CYAN << first_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Second array" << YELLOW << "[0]" << RESET << " -> " << CYAN << second_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Third array" << YELLOW << "[0]" << RESET << " -> " << CYAN << third_array[0] << RESET << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << "- " << RED << "Error" << RESET << ": " << RED << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "-----------------------------" << RESET << std::endl;
		std::cout << YELLOW << "DOUBLE" << RESET << std::endl;
		try 
		{
			Array<double>	first_array(5);

			std::cout << YELLOW << " array size" << RESET << " -> " << CYAN << first_array.size() << RESET << std::endl;
			first_array[0] = 42.4;
			Array<double> second_array(first_array);
			first_array[0] = 21.4;
			Array<double> third_array = second_array;
			second_array[0] = 84.4;
			std::cout << " - " << CYAN << "First array" << YELLOW << "[0]" << RESET << " -> " << CYAN << first_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Second array" << YELLOW << "[0]" << RESET << " -> " << CYAN << second_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Third array" << YELLOW << "[0]" << RESET << " -> " << CYAN << third_array[0] << RESET << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << "- " << RED << "Error" << RESET << ": " << RED << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "-----------------------------" << RESET << std::endl;
		std::cout << YELLOW << "STRING" << RESET << std::endl;
		try 
		{
			std::string str[] =  {"first", "second", "third"};
			Array<std::string>	first_array(5);

			std::cout << YELLOW << " array size" << RESET << " -> " << CYAN << first_array.size() << RESET << std::endl;
			first_array[0] = str[0];
			Array<std::string> second_array(first_array);
			first_array[0] = str[1];
			Array<std::string> third_array = second_array;
			second_array[0] = str[2];
			std::cout << " - " << CYAN << "First array" << YELLOW << "[0]" << RESET << " -> " << CYAN << first_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Second array" << YELLOW << "[0]" << RESET << " -> " << CYAN << second_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Third array" << YELLOW << "[0]" << RESET << " -> " << CYAN << third_array[0] << RESET << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << "- " << RED << "Error" << RESET << ": " << RED << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "-----------------------------" << RESET << std::endl;
		std::cout << YELLOW << "CHAR" << RESET << std::endl;
		try 
		{
			char str1[] = "first";
			char str2[] = "second";
			char str3[] = "third";
			Array<char *>	first_array(5);

			std::cout << YELLOW << " array size" << RESET << " -> " << CYAN << first_array.size() << RESET << std::endl;
			first_array[0] = str1;
			Array<char *> second_array(first_array);
			first_array[0] = str2;
			Array<char *> third_array = second_array;
			second_array[0] = str3;
			std::cout << " - " << CYAN << "First array" << YELLOW << "[0]" << RESET << " -> " << CYAN << first_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Second array" << YELLOW << "[0]" << RESET << " -> " << CYAN << second_array[0] << RESET << std::endl;
			std::cout << " - " << CYAN << "Third array" << YELLOW << "[0]" << RESET << " -> " << CYAN << third_array[0] << RESET << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << "- " << RED << "Error" << RESET << ": " << RED << e.what() << RESET << std::endl;
		}
		std::cout << MAGENTA << "-----------------------------" << RESET << std::endl;
		std::cout << MAGENTA << "******************" <<  RESET << std::endl;
	}
}
