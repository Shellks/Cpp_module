/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:53:04 by acarlott          #+#    #+#             */
/*   Updated: 2023/12/01 14:37:29 by acarlott         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	~MateriaSource();

	MateriaSource &operator=(MateriaSource const &src);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);

private:
	AMateria *_invMateriaSrc[4];
};

#endif
