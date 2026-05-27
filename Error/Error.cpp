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

ComputorError::ErrorType	ComputorError::getType() const
{
	return (_type);
}
