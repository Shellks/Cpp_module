/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:04:00 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/17 15:48:28 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>

template<typename T>
class Array 
{
	private:
		T				*_array;
		unsigned int	_array_size;

	public:
		Array() : _array_size(0) {
			this->_array = new T[_array_size];
		}
		Array(unsigned int size) : _array_size(size) {
			this->_array = new T[_array_size];
		}
		Array(Array const &src) {
			if (this != &src) {
				this->_array_size = src._array_size;
				this->_array = new T[this->_array_size];
				for (unsigned int i = 0; i < this->_array_size; i++) {
					this->_array[i] = src._array[i];
				}
			}
		}
		~Array() {
			if (this->_array)
				delete [] (this->_array);
		}
		
		Array &operator=(Array const &src) {
			if (this != &src) {
				this->_array_size = src._array_size;
				delete [] this->_array;
				this->_array = new T[this->_array_size];
				for (unsigned int i = 0; i < this->_array_size; i++) {
					this->_array[i] = src._array[i];
				}
			}
			return (*this);
		}
		T &operator[](unsigned int index) const {
			if (index >= this->_array_size)
				throw(Array::OutOfBoundException());
			return (this->_array[index]);
		}

		unsigned int size(void) {
			return (this->_array_size);
		}

		class OutOfBoundException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("index is out of bounds");
				};
		};
};

#endif
