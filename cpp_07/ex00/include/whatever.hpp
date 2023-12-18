/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:11:42 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/18 16:30:44 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef Whatever_HPP
#define Whatever_HPP

#define RESET "\033[0m"
#define BROWN "\033[0;33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#include <iostream>

template<typename T>
void swap(T &x, T &y){
	T temp = x;
	x = y;
	y = temp;
}

template<typename T>
T const &max(T const &x, T const &y) {
	return ((x > y) ? x : y);
}

template<typename T>
T const &min(T const &x, T const &y) {
	return ((x < y) ? x : y);
}

#endif