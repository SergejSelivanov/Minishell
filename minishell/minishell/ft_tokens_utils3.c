/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:45:58 by wjena             #+#    #+#             */
/*   Updated: 2020/12/25 14:46:25 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_check_token_dop1_3(t_parser *parser, int *i)
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

int				ft_check_token_dop1(t_parser *parser, int *i)
{
	while (parser->crtline[*i] != '\0')
	{
		if (parser->crtline[*i] == '"')
		{
			if (ft_check_token_dop1_2(parser, i) == 1)
				return (1);
			continue ;
		}
		if (parser->crtline[*i] == '\'')
		{
			if (ft_check_token_dop1_3(parser, i) == 1)
				return (1);
			continue ;
		}
		if (parser->crtline[*i] == ';')
			ft_check_token1(parser, *i);
		if (parser->if_synt_error == 1)
			return (1);
		*i += 1;
	}
	return (0);
}

int				ft_check_token_dop2_1(t_parser *parser, int *i)
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

int				ft_check_token_dop2_2(t_parser *parser, int *i)
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

int				ft_check_token_dop2(t_parser *parser, int *i)
{
	while (parser->crtline[*i] != '\0')
	{
		if (parser->crtline[*i] == '"')
		{
			if (ft_check_token_dop2_1(parser, i) == 1)
				return (1);
			continue ;
		}
		if (parser->crtline[*i] == '\'')
		{
			if (ft_check_token_dop2_2(parser, i) == 1)
				return (1);
			continue ;
		}
		if (parser->crtline[*i] == '|')
			ft_check_token2(parser, *i);
		if (parser->if_synt_error == 1)
			return (1);
		*i += 1;
	}
	return (0);
}
