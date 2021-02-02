/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_command1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:45:14 by wjena             #+#    #+#             */
/*   Updated: 2020/12/23 17:45:47 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_command4(t_parser *parser, int *i, int len, int *j)
{
	parser->params.commands[len][*j] = parser->crtline[*i];
	if (parser->params.flag_for_fill == 0)
		ft_fill_star_mas(parser, parser->crtline[*i]);
	*j += 1;
	*i += 1;
	parser->flag_pip = 0;
	parser->flag_ekr1 = 0;
}

int		ft_fill_command3(t_parser *parser, int *i, int len, int *j)
{
	if (parser->crtline[*i] == ' ' && parser->flap_sp1 == 0)
	{
		if (parser->crtline[*(i) - 1] != '>'
			&& parser->crtline[*(i) - 1] != '<'
			&& parser->flag1 == 1 && parser->flag_ekr1 != 1)
		{
			parser->flag1 = 0;
			parser->dmss++;
			parser->flag2 = 1;
		}
		parser->flag_spc++;
		parser->mas_col++;
		parser->params.commands[len][*j] = ' ';
		if (parser->flag_ekr1 == 1)
			ft_fill_star_mas(parser, ' ');
		*i += 1;
		*j += 1;
		if (parser->flag_ekr1 == 0)
			parser->params.flag_for_fill = 1;
		parser->flap_sp1 = 1;
		parser->flag_ekr1 = 0;
		return (1);
	}
	return (0);
}

void	ft_fill_command2(t_parser *parser, int *i)
{
	if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
	{
		if (parser->crtline[*(i) + 1] != '<'
			&& parser->crtline[*(i) + 1] != '>' && parser->flag_ekr1 != 1)
			parser->flag1 = 1;
	}
}
