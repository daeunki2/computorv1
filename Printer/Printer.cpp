/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 00:00:00 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/28 00:00:00 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printer.hpp"
#include "../Error/Error.hpp"
#include <iostream>

#define RESET          "\x1B[0m"
#define RED            "\x1B[31m"
#define LIGHT_RED      "\x1B[91m"
#define GREEN          "\x1B[32m"
#define YELLOW         "\x1B[33m"
#define BLUE           "\x1B[34m"
#define CYAN           "\x1B[36m"
#define MAGENTA        "\x1B[35m"
#define LIGHTMAGENTA   "\x1B[95m"

Printer::Printer()
{
}

Printer::Printer(const Printer& other)
{
	(void)other;
}

Printer::~Printer()
{
}

Printer& Printer::operator=(const Printer& other)
{
	(void)other;
	return (*this);
}

void	Printer::printInfo(const std::string& msg) const
{
	std::cout << msg << std::endl;
}

void	Printer::printError(const ComputorError& error) const
{
	const char*	typeName = "DEFAULT";
	const char*	defaultMessage = "unknown computor error";
	const char*	typeColor = RED;

	switch (error.getType())
	{
		case ComputorError::PARSE:
			typeName = "PARSE";
			defaultMessage = "failed to parse equation";
			typeColor = CYAN;
			break;
		case ComputorError::INVALID_CHARACTER:
			typeName = "INVALID_CHARACTER";
			defaultMessage = "invalid character found in input";
			typeColor = YELLOW;
			break;
		case ComputorError::INVALID_EXPONENT:
			typeName = "INVALID_EXPONENT";
			defaultMessage = "exponent must be a non-negative integer";
			typeColor = MAGENTA;
			break;
		case ComputorError::INVALID_FORMAT:
			typeName = "INVALID_FORMAT";
			defaultMessage = "invalid term format";
			typeColor = BLUE;
			break;
		case ComputorError::INVALID_EQUAL_SIGN:
			typeName = "INVALID_EQUAL_SIGN";
			defaultMessage = "equation must contain exactly one '='";
			typeColor = LIGHTMAGENTA;
			break;
		case ComputorError::EMPTY_INPUT:
			typeName = "EMPTY_INPUT";
			defaultMessage = "input is empty";
			typeColor = GREEN;
			break;
		case ComputorError::DEGREE_TOO_HIGH:
			typeName = "DEGREE_TOO_HIGH";
			defaultMessage = "polynomial degree is higher than 2";
			typeColor = LIGHT_RED;
			break;
		case ComputorError::DEFAULT:
		default:
			typeName = "DEFAULT";
			defaultMessage = "computor error";
			typeColor = RED;
			break;
	}

	std::string message = error.what();
	if (message.empty() || message == "Computor error")
		message = defaultMessage;
	std::cerr << LIGHT_RED << "[Error]" << RESET << " "
			  << typeColor << typeName << RESET
			  << " : " << message << std::endl;
}
