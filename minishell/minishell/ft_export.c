/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:00:46 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 17:57:17 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_export(char ***envp, char *str, t_parser *parser)
{
	char **strings;

	parser->dollar = 0;
	if ((ft_export_without_anyth(str, envp)) == 1)
		return (1);
	if (!(ft_strncmp("export", str, 6)) && (*(str + 6) == ' '))
	{
		if ((ft_export1(&str, *envp)) == 1)
			return (1);
		strings = ft_split(str, ' ');
		ft_export2(strings, parser, envp);
		ft_free_double_mass(strings);
		return (1);
	}
	return (0);
}

int		ft_export_without_anyth(char *str, char ***envp)
{
	int i;

	i = 0;
	if (!(ft_strncmp("export", str, 6)) && *(str + 6) == '\0')
	{
		while ((*envp)[i])
		{
			write(1, "declare -x ", 11);
			ft_printing_w_quotes((*envp)[i]);
			write(1, "\n", 1);
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_export1(char **str, char **envp)
{
	int i;

	i = 0;
	(*str) += 7;
	while (ft_strchr(" ", *(*str)))
	{
		if (ft_strchr(" ", *((*str) + 1)))
			(*str) += 1;
		else
			break ;
	}
	if (*(*str) == '\0')
	{
		while (envp[i])
		{
			write(1, "declare -x ", 11);
			ft_printing_w_quotes(envp[i]);
			write(1, "\n", 1);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_export2(char **strings, t_parser *parser, char ***envp)
{
	int *ints;

	ints = (int *)malloc(sizeof(int) * 4);
	ft_export_init_ints(&ints);
	while (strings[ints[1]])
	{
		ft_export_do_zero(&ints);
		if (!(ft_export_srch(strings[ints[1]], *envp)))
			while (strings[ints[1]][ints[0]])
			{
				if ((ft_isalpha(strings[ints[1]][0]) || strings[ints[1]][0]
				== '_') && ft_check_symb_before_eq(strings[ints[1]]))
				{
					if ((ft_export4(strings, parser, envp, &ints)) == 1)
						break ;
				}
				else
				{
					ft_export3(strings, ints[1], parser);
					break ;
				}
			}
		ints[1]++;
	}
	free(ints);
}

int		ft_export4(char **strings, t_parser *parser, char ***envp, int **ints)
{
	parser->dollar = 0;
	if (strings[(*ints)[1]][(*ints)[0]] == '=' ||
	(*ints)[0] == (int)(ft_strlen(strings[(*ints)[1]]) - 1))
	{
		(*ints)[3] = 1;
		ft_export_check(strings[(*ints)[1]], envp, (*ints)[0]);
	}
	(*ints)[0] += 1;
	if ((*ints)[3] == 1)
	{
		while ((*envp)[(*ints)[2]] != NULL)
			(*ints)[2] += 1;
		parser->params.string_to_free[parser->params.string_index] =
		ft_strdup(strings[(*ints)[1]]);
		(*envp)[(*ints)[2]] =
		parser->params.string_to_free[parser->params.string_index];
		parser->params.string_index++;
		parser->params.string_to_free[parser->params.string_index] = NULL;
		(*envp)[(*ints)[2] + 1] = NULL;
		return (1);
	}
	return (0);
}
