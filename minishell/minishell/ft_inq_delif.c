/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inq_delif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:41:44 by wjena             #+#    #+#             */
/*   Updated: 2020/12/28 18:22:51 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_del_if(t_parser *parser, int *i, int *j, char **envp)
{
	int sum;
	int sum1;

	sum = 0;
	sum1 = 0;
	if (parser->crtline[*i] == '$')
	{
		*i += 1;
		sum = ft_check_env(parser, i, envp);
		ft_del_if_doll(parser, sum, j);
		return (1);
	}
	if (parser->crtline[*i] == '~')
	{
		*i += 1;
		sum1 = ft_check_home(envp);
		*j += sum1;
		ft_kon1(parser, sum1);
		parser->mas_col += sum1;
		parser->flap_sp = 0;
		return (1);
	}
	if ((ft_del_if_ekr(parser, i)) == 1)
		return (1);
	return (0);
}

void	ft_in_quot11(t_parser *parser, int *i, int *j, char **envp)
{
	*i += 1;
	while (parser->crtline[*i] != '"' && parser->crtline[*i] != '\0')
	{
		if (parser->crtline[*i] == '$')
		{
			*i += 1;
			ft_check_env3(parser, i, envp, j);
			continue ;
		}
		if (parser->crtline[*i] == '\\'
			&& ft_check_next(parser, *i) == 1)
			*i += 1;
		ft_in_quot11_pr(parser, i);
		parser->params.commands[parser->lenlen1][*j] = parser->crtline[*i];
		ft_flms(parser, i);
		*i += 1;
		*j += 1;
	}
	if (parser->crtline[*i] == '\0')
	{
		parser->flagvih = 1;
		return ;
	}
	*i += 1;
}

void	ft_in_quot12(t_parser *parser, int *i, int *j, int len)
{
	*i += 1;
	while (parser->crtline[*i] != '\'' && parser->crtline[*i] != '\0')
	{
		if (parser->crtline[*i] == '|')
			ft_fill_flags(parser, '1');
		if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
			ft_fill_flags_red(parser, '1');
		parser->params.commands[len][*j] = parser->crtline[*i];
		if (parser->params.flag_for_fill == 0)
			ft_fill_star_mas(parser, parser->crtline[*i]);
		if (parser->flag1 == 1)
			ft_fill_red_name(parser, parser->crtline[*i]);
		*i += 1;
		*j += 1;
	}
	if (parser->crtline[*i] == '\0')
	{
		parser->flagvih = 1;
		return ;
	}
	*i += 1;
}

int		ft_del_if1_ekr(t_parser *parser, int *i)
{
	if (parser->crtline[*i] == '\\')
	{
		*i += 1;
		parser->flag_ekr1 = 1;
		if (parser->crtline[*i] == '|')
		{
			ft_fill_flags(parser, '1');
			parser->flag_pip = 1;
		}
		if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
			ft_fill_flags_red(parser, '1');
		if (parser->crtline[*i] == '\0')
		{
			parser->flagvih = 1;
			return (1);
		}
		parser->flap_sp1 = 0;
	}
	return (0);
}

int		ft_del_if1(t_parser *parser, int *i, int *j, char **envp)
{
	if (parser->crtline[*i] == '\'')
	{
		ft_in_quot12(parser, i, j, parser->lenlen1);
		parser->flap_sp1 = 0;
		return (1);
	}
	if (parser->crtline[*i] == '$')
	{
		*i += 1;
		ft_check_env1(parser, i, envp, j);
		return (1);
	}
	if (parser->crtline[*i] == '~')
	{
		*i += 1;
		ft_fill_home(parser, envp, j);
		parser->flap_sp1 = 0;
		return (1);
	}
	if (ft_del_if1_ekr(parser, i) == 1)
		return (1);
	return (0);
}
