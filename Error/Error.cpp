/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:12:46 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/27 19:23:37 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

ComputorError::ComputorError()
	: std::runtime_error("Computor error"), _type(DEFAULT)
{
}

ComputorError::ComputorError(const std::string& msg, ErrorType type)
	: std::runtime_error(msg), _type(type)
{
}

ComputorError::ComputorError(const ComputorError& other)
	: std::runtime_error(other.what()), _type(other._type)
{
}

ComputorError& ComputorError::operator=(const ComputorError& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

ComputorError::~ComputorError() throw()
{
}

void	ComputorError::print() const
{
	const char*	typeName = "DEFAULT";
	const char*	defaultMessage = "unknown computor error";
	const char*	typeColor = RED;

	switch (_type)
	{
		case PARSE:
			typeName = "PARSE";
			defaultMessage = "failed to parse equation";
			typeColor = CYAN;
			break;
		case INVALID_CHARACTER:
			typeName = "INVALID_CHARACTER";
			defaultMessage = "invalid character found in input";
			typeColor = YELLOW;
			break;
		case INVALID_EXPONENT:
			typeName = "INVALID_EXPONENT";
			defaultMessage = "exponent must be a non-negative integer";
			typeColor = MAGENTA;
			break;
		case INVALID_FORMAT:
			typeName = "INVALID_FORMAT";
			defaultMessage = "invalid term format";
			typeColor = BLUE;
			break;
		case INVALID_EQUAL_SIGN:
			typeName = "INVALID_EQUAL_SIGN";
			defaultMessage = "equation must contain exactly one '='";
			typeColor = LIGHTMAGENTA;
			break;
		case EMPTY_INPUT:
			typeName = "EMPTY_INPUT";
			defaultMessage = "input is empty";
			typeColor = GREEN;
			break;
		case DEGREE_TOO_HIGH:
			typeName = "DEGREE_TOO_HIGH";
			defaultMessage = "polynomial degree is higher than 2";
			typeColor = LIGHT_RED;
			break;
		case DEFAULT:
		default:
			typeName = "DEFAULT";
			defaultMessage = "computor error";
			typeColor = RED;
			break;
	}

	std::string message = what();
	if (message.empty() || message == "Computor error")
		message = defaultMessage;
	std::cerr << LIGHT_RED << "[Error]" << RESET << " " << typeColor << typeName << RESET << " : " << message << std::endl;
}
