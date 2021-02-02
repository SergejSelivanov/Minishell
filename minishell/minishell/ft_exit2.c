/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:41:38 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 17:53:47 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit5(t_parser *parser, char ***strings)
{
	int numb;

	numb = ft_atoi((*strings)[0]);
	numb = numb % 256;
	ft_free_double_mass((*strings));
	ft_free_double_mass(parser->params.string_to_free);
	write(1, "exit\n", 5);
	exit(numb);
}

void	ft_exit6(t_parser *parser, char ***strings)
{
	if (((*strings)[0][0] == '-' && ft_strlen((*strings)[0]) >= 20)
	|| ft_strlen((*strings)[0]) >= 19)
		ft_exit2(parser, strings);
	else if ((*strings)[0][0] == '-' && (*strings)[0][1] &&
	ft_isnum((*strings)[0][1]))
		ft_exit3(parser, strings);
	if (!(ft_if_number((*strings)[0])))
		ft_exit2(parser, strings);
	else if ((*strings)[1] != NULL)
		ft_exit4(parser);
	else
		ft_exit5(parser, strings);
}
