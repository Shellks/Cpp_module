/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:35:55 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/18 19:58:56 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename A, typename F>
void iter(A *aray_tab, size_t array_size, F (*ft)(A &src))
{
	for (size_t i = 0; i < array_size; i++)
		ft(aray_tab[i]);
};

template<typename A, typename F>
void iter(A const *aray_tab, size_t array_size, F (*ft)(A const &src))
{
	for (size_t i = 0; i < array_size; i++)
		ft(aray_tab[i]);
};

template<typename A>
void print_iter(A const element)
{
	std::cout << element << std::endl;
};

#endif
