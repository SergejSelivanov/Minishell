/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:37:49 by wjena             #+#    #+#             */
/*   Updated: 2020/12/25 14:46:26 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_check_token_dop3_1(t_parser *parser, int *i)
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

int				ft_check_token_dop3_2(t_parser *parser, int *i)
{
	*i += 1;
	while (parser->crtline[*i] != '\'')
	{
		if (parser->crtline[*i] == '\0')
			return (1);
		*i += 1;
	}
	*i += 1;
	return (0);
}

int				ft_check_token_dop3(t_parser *parser, int *i)
{
	while (parser->crtline[*i] != '\0')
	{
		if (parser->crtline[*i] == '"')
		{
			if (ft_check_token_dop3_1(parser, i) == 1)
				return (1);
			continue ;
		}
		if (parser->crtline[*i] == '\'')
		{
			if (ft_check_token_dop3_2(parser, i) == 1)
				return (1);
			continue ;
		}
		if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
			ft_check_token3(parser, *i);
		if (parser->if_synt_error == 1)
			return (1);
		*i += 1;
	}
	return (0);
}

void			ft_check_token(t_parser *parser)
{
	int i;

	i = 0;
	if (ft_check_token_dop1(parser, &i) == 1)
		return ;
	i = 0;
	if (ft_check_token_dop2(parser, &i) == 1)
		return ;
	i = 0;
	if (ft_check_token_dop3(parser, &i) == 1)
		return ;
}
