/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:20:09 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/22 17:26:22 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:
		Brain();
		Brain(std::string name);
		Brain( Brain const &src );
		~Brain();

		std::string	ideas[100];

		Brain &operator=( Brain const &src );
};

#endif
