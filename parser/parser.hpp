/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:56:21 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/27 19:35:07 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <map>

/*
basic idea
우선 간단한 확인을 한다. 
*/
class Parser
{
	private:
		std::string _line; // 원본 라인
		std::map<int, double> _polynomial; // 파싱후 얌전히 담긴 값들. 

	private:
		void	preprocessInput(const std::string& input);

	public:
		Parser();
		Parser(const Parser &other);
		~Parser();
		Parser &operator=(const Parser &other);

		void	parse(const std::string& equation);

		void	clear();

		std::map<int, double> getPolynomial() const;
};

#endif