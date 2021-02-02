/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:14:32 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 14:17:21 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(char **envp, char *str, t_parser *parser)
{
	int i;

	i = 0;
	if (!(ft_strncmp("env", str, 3)) && (*(str + 3) == ' ' || !(*(str + 3))))
	{
		while (envp[i])
		{
			if (ft_find_eq(envp[i]))
			{
				write(1, envp[i], ft_strlen(envp[i]));
				write(1, "\n", 1);
			}
			i++;
		}
		parser->dollar = 0;
		return (1);
	}
	return (0);
}

int		ft_find_eq(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
