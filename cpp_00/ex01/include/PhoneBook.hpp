/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:26:19 by acarlott          #+#    #+#             */
/*   Updated: 2023/11/09 15:12:32 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

//standard in/out include
# include <iostream>
// std::stw include
# include <iomanip>
// std::numeric_limits and std::streamsize incude
# include <limits>
// std::isspace include
# include <cctype>
// std::exit include
# include <cstdlib>
// own include
# include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	int		_index;
	
	void	addcontact(void);
	void	searchcontact(void) const;
	int		getindex(void) const;

private :

	Contact	_contacts[8];
	void	_introduction(void) const;
	void	_getcontact(void) const;
	void	_replacecontact(void);

};

#endif
