/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_exists2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 12:27:29 by festermo          #+#    #+#             */
/*   Updated: 2020/12/25 12:30:31 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_if_exists5(t_parser *parser)
{
	parser->ifex.i++;
	free(parser->ifex.buf);
	free(parser->ifex.path_append);
}

void	ft_check_if_exists6(t_parser *parser)
{
	parser->ifex.i = 0;
	parser->ifex.j = 0;
	parser->ifex.counter = 0;
}

int		ft_check_if_our_func(char *str, char *to_find)
{
	if (!(ft_strncmp(str, to_find, ft_strlen(to_find))) &&
	*(str + ft_strlen(to_find)) == '\0')
		return (1);
	else
		return (0);
}
