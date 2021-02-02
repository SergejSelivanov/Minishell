/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inq_delif1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:37:26 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 17:13:07 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_del_if_ekr(t_parser *parser, int *i)
{
	if (parser->crtline[*i] == '\\')
	{
		*i += 1;
		parser->flap_sp = 0;
		parser->flag_ekr = 1;
		if (parser->crtline[*i] == '\0')
		{
			parser->flagvih = 1;
			return (1);
		}
	}
	return (0);
}

void	ft_del_if_doll(t_parser *parser, int sum, int *j)
{
	*j += sum;
	parser->mas_col += sum;
	if (parser->flag1 == 1)
		parser->flag_red_name_col += sum;
	if (sum == 0)
		parser->flap_sp = 1;
	else
		parser->flap_sp = 0;
}

void	ft_in_quot11_pr(t_parser *parser, int *i)
{
	if (parser->crtline[*i] == '|')
		ft_fill_flags(parser, '1');
	if (parser->crtline[*i] == '<' || parser->crtline[*i] == '>')
		ft_fill_flags_red(parser, '1');
}
