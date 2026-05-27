/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:56:24 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/28 00:09:17 by daeunki2         ###   ########.fr       */
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
// 3) 빈 문장인지 검사. 
void	Parser::preprocess_Input( )
{
	int equalCount = 0;
	if (_line.find_first_not_of(" \t\n\r\v\f") == std::string::npos)
	{
		throw ComputorError("Nothing to solve", ComputorError::EMPTY_INPUT);
	}

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
	preprocess_Input();
	// 문자열에서 =의 위치를 찾아서 일단 2개로 나누고 각 변에 값이 있는지 확인. 
	size_t pos = equation.find('=');
	std::string left = equation.substr(0, pos);
	std::string right = equation.substr(pos + 1);
	// 하나씩 처리하면서 값을담는다. 단 pos을 이용하여 저장할때 좌변인지 우변인지 저장
}

std::vector<Term> Parser::get_terms() const
{
	return (_polynomial);
}
