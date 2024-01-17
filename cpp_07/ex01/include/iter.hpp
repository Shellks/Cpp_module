/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:35:55 by acarlott          #+#    #+#             */
/*   Updated: 2024/01/17 15:03:23 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef Whatever_HPP
#define Whatever_HPP

#include <iostream>

template<typename A, typename I, typename F>
void iter(A *aray_tab, I array_size, F (*ft)(A src))
{
	for (I i = 0; i < array_size; i++)
		ft(aray_tab[i]);
};

template<typename A, typename I, typename F>
void iter(A const *aray_tab, I array_size, F const (*ft)(A const src))
{
	for (I i = 0; i < array_size; i++)
		ft(aray_tab[i]);
};

template<typename A>
void print_iter(A const element)
{
	std::cout << element << std::endl;
};

#endif
