/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:22:33 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 17:56:01 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_unset(char ***envp, char *str, t_parser *parser)
{
	int		j;
	char	**strings;

	parser->dollar = 0;
	j = 0;
	if (!(ft_strncmp("unset", str, 5)) && (*(str + 5) == ' ' || !(*(str + 5))))
	{
		str += 5;
		while (ft_strchr(" ", *str))
			str++;
		strings = ft_split(str, ' ');
		while (strings[j])
		{
			if ((ft_isalpha(strings[j][0]) || strings[j][0] == '_') &&
			!(ft_find_eq(strings[j])) && ft_check_symb_before_eq(strings[j]))
				ft_unset2(strings, envp, &j);
			else
				ft_unset3(parser, strings, &j);
		}
		ft_free_double_mass(strings);
		return (1);
	}
	return (0);
}

void	ft_unset2(char **strings, char ***envp, int *j)
{
	int i;
	int k;

	i = 0;
	k = 0;
	k = ft_find_in_env((*envp), strings[*j]);
	if (k != -1)
	{
		while ((*envp)[k] != NULL)
		{
			(*envp)[k] = (*envp)[k + 1];
			k++;
		}
	}
	*j += 1;
}

void	ft_unset3(t_parser *parser, char **strings, int *j)
{
	write(1, "minishell: unset: `", 19);
	write(1, strings[*j], ft_strlen(strings[*j]));
	write(1, "': not a valid identifier\n", 26);
	parser->dollar = 1;
	*j += 1;
}
