/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:44:53 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 17:53:58 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exit(char *str, t_parser *parser)
{
	char	**strings;

	if (!(ft_strncmp("exit", str, 4)))
	{
		if ((*(str + 4)) == '\0')
			ft_exit1(parser);
		else if ((*(str + 4)) == ' ')
		{
			strings = ft_split(str + 4, ' ');
			ft_exit6(parser, &strings);
		}
		return (1);
	}
	return (0);
}

void	ft_exit1(t_parser *parser)
{
	ft_free_double_mass(parser->params.string_to_free);
	write(1, "exit\n", 5);
	exit(parser->dollar);
}

void	ft_exit2(t_parser *parser, char ***strings)
{
	write(1, "exit\nminishell: exit: ", 22);
	write(1, (*strings)[0], ft_strlen((*strings)[0]));
	write(1, ": numeric argument required\n", 28);
	ft_free_double_mass((*strings));
	ft_free_double_mass(parser->params.string_to_free);
	exit(255);
}

void	ft_exit3(t_parser *parser, char ***strings)
{
	int numb;

	numb = ft_atoi((*strings)[0] + 1);
	numb = numb % 256;
	ft_free_double_mass((*strings));
	write(1, "exit\n", 5);
	ft_free_double_mass(parser->params.string_to_free);
	exit(256 - numb);
}

void	ft_exit4(t_parser *parser)
{
	write(1, "exit\nminishell: exit: too many arguments\n", 41);
	parser->dollar = 1;
}
