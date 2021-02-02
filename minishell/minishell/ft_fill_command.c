/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:47:31 by wjena             #+#    #+#             */
/*   Updated: 2020/12/23 17:45:40 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_command1(t_parser *parser, int *i)
{
	parser->flap_sp1 = 0;
	if (parser->crtline[*i] == '|' && parser->flag_pip == 0)
		ft_fill_flags(parser, '0');
	if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
		ft_fill_flags_red(parser, '0');
	if (parser->crtline[*i] == '|' && parser->flag_ekr1 != 1
		&& parser->flag1 == 1)
	{
		parser->flag1 = 0;
		parser->dmss++;
	}
	if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
	{
		if (parser->flag2 == 0 && parser->pr != 0
			&& parser->flag_ekr1 != 1 && parser->flag1 == 1)
		{
			parser->flag1 = 0;
			parser->dmss++;
		}
		parser->pr++;
		parser->flag2 = 0;
	}
	if (parser->flag1 == 1)
		ft_fill_red_name(parser, parser->crtline[*i]);
}

void	ft_fill_init(t_parser *parser, int len)
{
	parser->params.flag_for_fill = 0;
	parser->flag_red_name2 = 0;
	parser->flap_sp1 = 0;
	parser->flag_pip = 0;
	parser->lenlen1 = len;
	parser->lenlen = len;
	parser->flag_ekr1 = 0;
	parser->flag_spc = 0;
	parser->dmss = 0;
	parser->flag1 = 0;
	parser->flag2 = 0;
	parser->pr = 0;
}

int		ft_fill_command5(t_parser *parser, int *i)
{
	if (parser->crtline[*i] == ' ' && parser->flap_sp1 == 1)
	{
		*i += 1;
		parser->flag_ekr1 = 0;
		return (1);
	}
	return (0);
}

int		ft_fill_command6(t_parser *parser, int *i, int *j, char **envp)
{
	if (parser->crtline[*i] == '"')
	{
		ft_in_quot11(parser, i, j, envp);
		parser->flap_sp1 = 0;
		return (1);
	}
	return (0);
}

void	ft_fill_command(t_parser *parser, int len, int *i, char **envp)
{
	int j;

	j = 0;
	ft_fill_init(parser, len);
	ft_skip_space(parser, i);
	while (parser->crtline[*i] != '\0')
	{
		if (ft_fill_command6(parser, i, &j, envp) == 1)
			continue ;
		if (parser->crtline[*i] == ';')
		{
			*i += 1;
			return ;
		}
		if (ft_del_if1(parser, i, &j, envp) == 1)
			continue ;
		if (ft_fill_command3(parser, i, len, &j) == 1)
			continue ;
		if (ft_fill_command5(parser, i) == 1)
			continue ;
		ft_fill_command1(parser, i);
		ft_fill_command2(parser, i);
		ft_fill_command4(parser, i, len, &j);
	}
}
