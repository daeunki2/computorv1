/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:12:43 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/27 19:24:42 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
#define ERROR_HPP

#include <stdexcept>
#include <string>
#include <iostream>

/*
ANSI Color
*/

#define RESET          "\x1B[0m"
#define RED            "\x1B[31m"
#define LIGHT_RED      "\x1B[91m"
#define GREEN          "\x1B[32m"
#define YELLOW         "\x1B[33m"
#define BLUE           "\x1B[34m"
#define CYAN           "\x1B[36m"
#define MAGENTA        "\x1B[35m"
#define LIGHTMAGENTA   "\x1B[95m"

/*
Computor Error
*/

class ComputorError : public std::runtime_error
{
public:

	enum ErrorType
	{
		DEFAULT, 
		PARSE,
		INVALID_CHARACTER,
		INVALID_EXPONENT,
		INVALID_FORMAT,
		INVALID_EQUAL_SIGN,
		EMPTY_INPUT, 
		DEGREE_TOO_HIGH
	};

private:

	ErrorType _type;

public:

	// Orthodox Canonical Form
	ComputorError();
	explicit ComputorError(const std::string& msg, ErrorType type = DEFAULT);
	ComputorError(const ComputorError& other);
	ComputorError& operator=(const ComputorError& other);

	virtual ~ComputorError() throw();

	// custom methods
	void print() const;
};

#endif
