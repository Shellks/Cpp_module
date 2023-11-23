/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:20:09 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/23 13:14:42 by acarlott         ###   ########lyon.fr   */
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
		Brain( Brain const &src );
		~Brain();

		std::string	ideas[100];

		Brain &operator=( Brain const &src );

		std::string	getIdeas( int index ) const;
		void		setIdeas( int index, std::string ideas );
};

#endif
