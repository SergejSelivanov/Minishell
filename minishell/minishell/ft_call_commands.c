/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:45:29 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 15:44:55 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_call_commands6(t_parser *parser, int *i, int *j)
{
	if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
	{
		parser->params.col_redir++;
		if (parser->crtline[(*i) + 1] != '<'
			&& parser->crtline[(*i) + 1] != '>' && parser->flag_ekr != 1)
			parser->flag1 = 1;
	}
	parser->flag_ekr = 0;
	*j += 1;
	*i += 1;
	parser->mas_col++;
}

void	ft_call_commands7(t_parser *parser, int flaggg)
{
	if (parser->flag1 == 1)
		ft_calloc_red_name(parser);
	ft_call_flags(parser);
	ft_call_flags_red(parser);
	if (flaggg == 0)
		ft_call_starmass(parser);
}

int		ft_call_commands8(t_parser *parser, int *i)
{
	if (parser->crtline[*i] == ' ' && parser->flap_sp == 1)
	{
		*i += 1;
		parser->flag_ekr = 0;
		return (1);
	}
	return (0);
}

int		ft_call_commands9(t_parser *parser, int *i, int flaggg)
{
	if (parser->crtline[*i] == ';')
	{
		ft_call_commands3(parser, flaggg);
		return (1);
	}
	return (0);
}

int		ft_call_commands(t_parser *parser, int i, char **envp)
{
	int j;
	int flaggg;

	j = 0;
	flaggg = 0;
	ft_call_commands_init(parser);
	ft_skip_space(parser, &i);
	ft_quanred_quot(parser);
	while (parser->crtline[i] != '\0')
	{
		if (ft_call_commands2(parser, &i, &j, envp) == 1)
			continue ;
		if (ft_call_commands9(parser, &i, flaggg) == 1)
			return (ft_call_commands1(parser, j));
		if (ft_del_if(parser, &i, &j, envp) == 1)
			continue ;
		if (ft_call_commands4(parser, flaggg, &i, &j) == 1)
			continue ;
		if (ft_call_commands8(parser, &i) == 1)
			continue ;
		ft_call_commands5(parser, &i);
		ft_call_commands6(parser, &i, &j);
	}
	ft_call_commands7(parser, flaggg);
	return (ft_call_commands1(parser, j));
}
