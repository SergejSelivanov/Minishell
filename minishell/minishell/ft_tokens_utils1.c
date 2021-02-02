/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:39:57 by wjena             #+#    #+#             */
/*   Updated: 2020/12/25 14:43:04 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_check_token3_dop(t_parser *parser)
{
	write(1, "minishell: syntax error near", 28);
	write(1, " unexpected token `newline'\n", 28);
	parser->dollar = 258;
	parser->if_synt_error = 1;
	return (1);
}

int				ft_check_token3_dop1(int i, int k, t_parser *parser, int flag)
{
	if ((parser->crtline[i] == '\0' || parser->crtline[i] == '>'
		|| parser->crtline[i] == '<') && parser->crtline[i - 2] != '\\')
		if (ft_check_token3_dop(parser) == 1)
			return (1);
	if (k == 0 && flag == 0)
		if (ft_check_token3_dop(parser) == 1)
			return (1);
	if (k == 0 && flag == 1)
		return (1);
	if (parser->crtline[k + 1] == '\0' && parser->crtline[k] == '<')
		if (parser->crtline[k - 1] != '\\')
			if (ft_check_token3_dop(parser) == 1)
				return (1);
	if (parser->crtline[k + 1] == '\0' && parser->crtline[k] == '>')
		if (parser->crtline[k - 1] != '\\')
			if (ft_check_token3_dop(parser) == 1)
				return (1);
	return (0);
}

int				ft_check_token3_dop2(int *k, t_parser *parser, int flag)
{
	while (parser->crtline[*k] != '<' && parser->crtline[*k] != '>' && *k >= 0)
	{
		if (parser->crtline[*k] != ' ')
			return (1);
		*k -= 1;
		if (*k == -1 && flag == 0)
			if (ft_check_token3_dop(parser) == 1)
				return (1);
		if ((parser->crtline[*k] == '<' || parser->crtline[*k] == '>')
			&& *k != 0)
			if (parser->crtline[(*k) - 1] == '\\')
				*k -= 1;
	}
	return (0);
}

void			ft_check_token3_dop3(t_parser *parser, int *i, int *flag)
{
	while (parser->crtline[*i] != '\0' && parser->crtline[*i] != '>'
		&& parser->crtline[*i] != '<')
	{
		if (parser->crtline[*i] != ' ')
		{
			*flag = 1;
			break ;
		}
		*i += 1;
	}
}

void			ft_check_token3(t_parser *parser, int k)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	i = k;
	i++;
	if (parser->crtline[i] == '>')
		i++;
	ft_check_token3_dop3(parser, &i, &flag);
	if (ft_check_token3_dop1(i, k, parser, flag) == 1)
		return ;
	k--;
	if (ft_check_token3_dop2(&k, parser, flag) == 1)
		return ;
	if (flag == 1)
		return ;
	if (ft_check_token3_dop(parser) == 1)
		return ;
}
