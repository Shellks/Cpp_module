/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:23:54 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/18 11:30:23 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
 
int main() 
{
	Base *test = generate();
	identify(test);
	identify(*test);
	
	delete test;
}