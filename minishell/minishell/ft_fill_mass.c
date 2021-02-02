/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_mass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:58:32 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 16:47:28 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_endparser(t_parser *parser, int i)
{
	parser->flag1 = 0;
	if (i == 1)
	{
		write(1, "malloc error", 12);
		write(1, "\n", 1);
		exit(0);
	}
	if (i == 2)
	{
		write(1, "multiple line", 13);
		write(1, "\n", 1);
		exit(0);
	}
	exit(0);
}

void	ft_fill_star_mas(t_parser *parser, char c)
{
	int i;

	i = 0;
	while (parser->params.starmass[i] != '\0')
		i++;
	parser->params.starmass[i] = c;
}

void	ft_fill_red_name(t_parser *parser, char c)
{
	int i;

	i = 0;
	while (parser->mass_for_names[parser->dmss][i] != '\0')
		i++;
	parser->mass_for_names[parser->dmss][i] = c;
}

void	ft_fill_flags(t_parser *parser, char c)
{
	int i;

	i = 0;
	while (parser->params.flagsp[i] != '\0')
		i++;
	parser->params.flagsp[i] = c;
}

void	ft_fill_flags_red(t_parser *parser, char c)
{
	int i;

	i = 0;
	while (parser->params.flagsr[i] != '\0')
		i++;
	parser->params.flagsr[i] = c;
}
