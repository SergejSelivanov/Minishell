/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:24:14 by wjena             #+#    #+#             */
/*   Updated: 2020/12/23 18:54:26 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_skip_space(t_parser *parser, int *i)
{
	while (parser->crtline[*i] == ' ')
		*i += 1;
}

int		ft_check_home(char **envp)
{
	int j;

	j = 0;
	while (envp[j] != NULL)
	{
		if (ft_strncmp("HOME=", envp[j], 5) == 0)
			return (ft_skok_tam(envp[j], 5));
		j++;
	}
	return (0);
}

void	ft_free_double_mass(char **str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free(str);
		str = NULL;
	}
	return ;
}

void	ft_quanred_quot(t_parser *parser)
{
	int i;

	i = 0;
	parser->quanred = 0;
	while (parser->crtline[i] != '\0' && parser->crtline[i] != ';')
	{
		if (parser->crtline[i] == '>' || parser->crtline[i] == '<')
			parser->quanred++;
		i++;
	}
	ft_callred_quot(parser);
}
