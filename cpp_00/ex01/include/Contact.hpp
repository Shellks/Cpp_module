/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:26:13 by acarlott          #+#    #+#             */
/*   Updated: 2023/09/24 20:53:54 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

	public :

		Contact(void);
		~Contact(void);

		void		printsearchlist(void) const;
		void		printcontact(void) const;
		void		initcontact(void);
		std::string	getinput(void);

	private :

		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_darkestsecret;
		std::string	_phonenumber;

		std::string	_checklength(std::string str) const;

};

#endif