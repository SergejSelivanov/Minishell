/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skok_call_comm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:16:45 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 16:36:42 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_call_commands1(t_parser *parser, int len)
{
	if (!(parser->params.commands[parser->fl] = (char *)malloc(sizeof(char)
		* (len + 1))))
		ft_endparser(parser, 1);
	parser->params.commands[parser->fl][len] = '\0';
	return (parser->fl);
}

int		ft_check_space(t_parser *parser, int i)
{
	while (parser->crtline[i] != '\0' && parser->crtline[i] != ';')
	{
		if (parser->crtline[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_skok_tam(char *envp, int len)
{
	int i;

	i = 0;
	while (envp[len] != '\0')
	{
		len++;
		i++;
	}
	return (i);
}

void	ft_skok_tam1(char *envp, int len, t_parser *parser, int *m)
{
	while (envp[len] != '\0')
	{
		parser->params.commands[parser->lenlen][*m] = envp[len];
		if (parser->params.flag_for_fill == 0)
			ft_fill_star_mas(parser, envp[len]);
		if (parser->flag1 == 1)
			ft_fill_red_name(parser, envp[len]);
		len++;
		*m += 1;
	}
	return ;
}

void	ft_fill_dollar(t_parser *parser, int *m)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(parser->dollar);
	while (str[i] != '\0')
	{
		parser->params.commands[parser->lenlen][*m] = str[i];
		if (parser->params.flag_for_fill == 0)
			ft_fill_star_mas(parser, str[i]);
		if (parser->flag1 == 1)
			ft_fill_red_name(parser, str[i]);
		i++;
		*m += 1;
	}
	free(str);
	str = NULL;
	return ;
}
