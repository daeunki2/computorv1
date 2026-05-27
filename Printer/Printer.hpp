/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 00:00:00 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/28 00:00:00 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <string>

class ComputorError;

class Printer
{
public:
	Printer();
	Printer(const Printer& other);
	~Printer();

	Printer& operator=(const Printer& other);

	void	printInfo(const std::string& msg) const;
	void	printError(const ComputorError& error) const;
};

#endif
