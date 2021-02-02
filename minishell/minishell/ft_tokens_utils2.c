/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:43:11 by wjena             #+#    #+#             */
/*   Updated: 2020/12/25 14:43:57 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_check_token2_dop(t_parser *parser)
{
	write(1, "minishell: syntax error near unexpected token `|'\n", 51);
	parser->dollar = 258;
	parser->if_synt_error = 1;
	return (1);
}

void			ft_check_token2(t_parser *parser, int k)
{
	if (k == 0)
		if (ft_check_token2_dop(parser) == 1)
			return ;
	if (parser->crtline[k + 1] == '\0' && parser->crtline[k] == '|')
		if (parser->crtline[k - 1] != '\\')
			if (ft_check_token2_dop(parser) == 1)
				return ;
	k--;
	while (parser->crtline[k] != '|' && k >= 0)
	{
		if (parser->crtline[k] != ' ')
			return ;
		k--;
		if (k == -1)
			if (ft_check_token2_dop(parser) == 1)
				return ;
		if (parser->crtline[k] == '|' && k != 0)
			if (parser->crtline[k - 1] == '\\')
				k--;
	}
	if (ft_check_token2_dop(parser) == 1)
		return ;
}

void			ft_check_token1_dop(t_parser *parser)
{
	write(1, "minishell: syntax error near unexpected token `;'\n", 51);
	parser->dollar = 258;
	parser->if_synt_error = 1;
}

void			ft_check_token1(t_parser *parser, int k)
{
	if (k == 0)
	{
		ft_check_token1_dop(parser);
		return ;
	}
	k--;
	while (parser->crtline[k] != ';' && k >= 0)
	{
		if (parser->crtline[k] != ' ')
			return ;
		k--;
		if (k == -1)
		{
			ft_check_token1_dop(parser);
			return ;
		}
		if (parser->crtline[k] == ';' && k != 0)
			if (parser->crtline[k - 1] == '\\')
				k--;
	}
	ft_check_token1_dop(parser);
}

int				ft_check_token_dop1_2(t_parser *parser, int *i)
{
	*i += 1;
	while (parser->crtline[*i] != '"')
	{
		if (parser->crtline[*i] == '\0')
			return (1);
		*i += 1;
	}
	*i += 1;
	return (0);
}
