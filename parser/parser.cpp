/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:56:24 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/27 21:04:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"
#include "../Error/Error.hpp"
#include <iostream>
#include <cmath>
#include <cctype>

namespace
{
	bool	isAllowedChar(char c)
	{
		unsigned char uc = static_cast<unsigned char>(c);

		if (std::isdigit(uc) || std::isspace(uc))
			return (true);
		if (c == 'X' || c == 'x')
			return (true);
		if (c == '+' || c == '-' || c == '*' || c == '^' || c == '=' || c == '.')
			return (true);
		return (false);
	}
}

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
// 최소 전처리:
// 1) 허용되지 않은 문자 검사
// 2) '=' 개수 검사 (정확히 1개)
void	Parser::preprocessInput( )
{
	int equalCount = 0;

	for (std::string::const_iterator it = _line.begin(); it != _line.end(); ++it)
	{
		char c = *it;
		unsigned char uc = static_cast<unsigned char>(c);

		if (std::isalpha(uc) && c != 'X' && c != 'x')
			throw ComputorError("only variable X is allowed", ComputorError::INVALID_CHARACTER);
		if (!isAllowedChar(c))
			throw ComputorError("invalid symbol in input", ComputorError::INVALID_CHARACTER);
		if (c == '=')
			equalCount++;
	}
	if (equalCount != 1)
		throw ComputorError("equation must contain exactly one '='", ComputorError::INVALID_EQUAL_SIGN);
}

void	Parser::parse(const std::string& equation)
{
	// 여기까지는 초기화 + 아주 간단한 검사
	clear();
	_line = equation;
	preprocessInput();
	// 문자열에서 =의 위치를 찾아서 일단 2개로 나누기
	size_t pos = equation.find('=');
	std::string left = equation.substr(0, pos);
	std::string right = equation.substr(pos + 1);
	// 오른쪽 먼저 처리하고, 왼쪽은 부호를 바꿔서 맵에 담기. + 담는 과정에서는 유효성 검사하기
	
}

std::map<int, double> Parser::getPolynomial() const
{
	return (_polynomial);
}

void	Parser::printPolynomial() const
{
	bool first = true;
	bool hasTerm = false;

	std::cout << "Reduced form: ";
	for (std::map<int, double>::const_iterator it = _polynomial.begin(); it != _polynomial.end(); ++it)
	{
		double coef = it->second;
		int exp = it->first;

		if (std::fabs(coef) < 1e-12)
			continue;
		hasTerm = true;
		if (first)
		{
			if (coef < 0)
				std::cout << "-";
		}
		else
		{
			if (coef < 0)
				std::cout << " - ";
			else
				std::cout << " + ";
		}
		if (coef < 0)
			coef = -coef;
		std::cout << coef << " * X^" << exp;
		first = false;
	}
	if (!hasTerm)
		std::cout << "0 * X^0";
	std::cout << " = 0" << std::endl;
}
