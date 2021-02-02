/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_commands1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:45:45 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 17:14:36 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_call_commands_init(t_parser *parser)
{
	parser->flagvih = 0;
	parser->flap_sp = 0;
	parser->mas_col = 0;
	parser->flag_ekr = 0;
	parser->flag_spc = 0;
	parser->flag1 = 0;
	parser->flag_red_name_col = 0;
	parser->flag2 = 0;
	parser->pr = 0;
}

int		ft_call_commands2(t_parser *parser, int *i, int *j, char **envp)
{
	if (parser->crtline[*i] == '"')
	{
		ft_in_quot(parser, i, j, envp);
		parser->flap_sp = 0;
		return (1);
	}
	if (parser->crtline[*i] == '\'')
	{
		ft_in_quot1(parser, i, j);
		parser->flap_sp = 0;
		return (1);
	}
	return (0);
}

void	ft_call_commands3(t_parser *parser, int flaggg)
{
	ft_call_flags(parser);
	ft_call_flags_red(parser);
	if (flaggg == 0)
		ft_call_starmass(parser);
	if (parser->flag1 == 1)
		ft_calloc_red_name(parser);
}

int		ft_call_commands4(t_parser *parser, int flaggg, int *i, int *j)
{
	if (parser->crtline[*i] == ' ' && parser->flap_sp == 0)
	{
		if (parser->crtline[(*i) - 1] != '>'
			&& parser->crtline[(*i) - 1] != '<'
			&& parser->flag1 == 1 && parser->flag_ekr != 1)
		{
			parser->flag1 = 0;
			ft_calloc_red_name(parser);
			parser->flag2 = 1;
		}
		*i += 1;
		*j += 1;
		parser->mas_col++;
		parser->flag_spc++;
		if (flaggg == 0 && parser->flag_ekr == 0)
		{
			ft_call_starmass(parser);
			flaggg = 1;
		}
		parser->flag_ekr = 0;
		parser->flap_sp = 1;
		return (1);
	}
	return (0);
}

void	ft_call_commands5(t_parser *parser, int *i)
{
	parser->flap_sp = 0;
	if (parser->crtline[*i] == '|')
	{
		parser->params.col_pipe++;
	}
	if (parser->crtline[*i] == '|' && parser->flag_ekr != 1
		&& parser->flag1 == 1)
	{
		parser->flag1 = 0;
		ft_calloc_red_name(parser);
	}
	if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
	{
		if (parser->flag2 == 0 && parser->pr != 0
			&& parser->flag_ekr != 1 && parser->flag1 == 1)
		{
			parser->flag1 = 0;
			ft_calloc_red_name(parser);
		}
		parser->pr++;
		parser->flag2 = 0;
	}
	if (parser->flag1 == 1)
		parser->flag_red_name_col++;
}
