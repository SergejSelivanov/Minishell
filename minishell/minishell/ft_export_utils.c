/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:02:40 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 17:18:56 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printing_w_quotes(char *str)
{
	int j;
	int flag;

	flag = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == '=')
		{
			flag = 1;
			break ;
		}
		j++;
	}
	if (flag == 1)
	{
		write(1, str, j + 1);
		write(1, "\"", 1);
		str += (j + 1);
		write(1, str, ft_strlen(str));
		write(1, "\"", 1);
	}
	else
		write(1, str, ft_strlen(str));
}

void	ft_export_check(char *name, char ***envp, int i)
{
	int j;
	int k;

	k = 0;
	j = 0;
	while ((*envp)[j])
	{
		if (!(ft_strncmp(name, (*envp)[j], i)))
		{
			while ((*envp)[j] != NULL)
			{
				(*envp)[j] = (*envp)[j + 1];
				j++;
			}
			return ;
		}
		j++;
	}
}

int		ft_export_srch(char *name, char **envp)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(name, envp[i], ft_strlen(name))))
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

void	ft_export_init_ints(int **ints)
{
	(*ints)[0] = 0;
	(*ints)[1] = 0;
	(*ints)[2] = 0;
	(*ints)[3] = 0;
	(*ints)[4] = 0;
}

void	ft_export_do_zero(int **ints)
{
	(*ints)[0] = 0;
	(*ints)[2] = 0;
}
