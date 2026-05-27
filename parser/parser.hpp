/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:56:21 by daeunki2          #+#    #+#             */
/*   Updated: 2026/05/28 00:01:21 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>


/*
basic idea
우선 간단한 확인을 한다. 
*/

struct Term
{
    double coef; // 계수
    int exp; // 지수(x의 2승 3승 )
    bool isLeft; // true: 좌변, false: 우변
};

class Parser
{
	private:
			std::string _line; // 원본 라인
			std::vector<Term> _polynomial; // 파싱후 얌전히 담긴 값들. 

	private:
			void	preprocess_Input();

	public:
		Parser();
		Parser(const Parser &other);
		~Parser();
		Parser &operator=(const Parser &other);

		void	parse(const std::string& equation);
		void	clear();

		std::vector<Term> get_terms() const;
};

#endif
