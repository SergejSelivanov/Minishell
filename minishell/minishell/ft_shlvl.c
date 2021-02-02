/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlvl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:21:16 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 18:24:57 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_if_shlvl(char **envp, t_func *func)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp("SHLVL", envp[i], 5)))
		{
			func->is_there_sh = 1;
			func->shlvl = ft_atoi((envp[i] + 6));
			func->index = i;
		}
		i++;
	}
}

void	ft_change_shlvl(char ***envp, t_func *func, t_parser *parser)
{
	char *buf;

	if (func->shlvl != 0)
		buf = ft_itoa(func->shlvl + 1);
	else
	{
		buf = (char *)malloc(sizeof(char) * 2);
		buf[0] = '1';
		buf[1] = '\0';
	}
	parser->params.string_to_free[parser->params.string_index] =
	ft_strjoin("SHLVL=", buf);
	free(buf);
	(*envp)[func->index] =
	parser->params.string_to_free[parser->params.string_index];
	parser->params.string_index++;
	parser->params.string_to_free[parser->params.string_index] = NULL;
}

void	ft_make_shlvl(char ***envp, t_parser *parser)
{
	int k;

	k = 0;
	while ((*envp)[k])
		k++;
	parser->params.string_to_free[parser->params.string_index] =
	ft_strdup("SHLVL=1");
	(*envp)[k] = parser->params.string_to_free[parser->params.string_index];
	parser->params.string_index++;
	parser->params.string_to_free[parser->params.string_index] = NULL;
	(*envp)[k + 1] = NULL;
}
