/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:56:24 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/27 19:34:57 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"

Parser::Parser()
{
	
}

Parser::Parser(const Parser &other)
{
	*this = other;
}

Parser::~Parser()
{
}

Parser &Parser::operator=(const Parser &other)
{
	if (this != &other)
	{
		_line = other._line;
		_polynomial = other._polynomial;
	}
	return (*this);
}

void	Parser::clear()
{
	_line.clear();
	_polynomial.clear();
}
void	Parser::preprocessInput(const std::string& input)
{
	
}

void	Parser::parse(const std::string& equation)
{
	clear();
	_line = equation;
	// TODO: add checker + parsing flow here
}

std::map<int, double> Parser::getPolynomial() const
{
	return (_polynomial);
}
