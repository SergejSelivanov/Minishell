/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:38:04 by wjena             #+#    #+#             */
/*   Updated: 2020/12/24 18:44:49 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_kon1(t_parser *parser, int sum1)
{
	if (parser->flag1 == 1)
		parser->flag_red_name_col += sum1;
}

void	ft_flms(t_parser *parser, int *i)
{
	if (parser->params.flag_for_fill == 0)
		ft_fill_star_mas(parser, parser->crtline[*i]);
	if (parser->flag1 == 1)
		ft_fill_red_name(parser, parser->crtline[*i]);
}

void	ft_in_quot_dop(t_parser *parser, int col, int *j)
{
	*j += col;
	parser->mas_col += col;
	if (parser->flag1 == 1)
		parser->flag_red_name_col += col;
}

void	ft_check_enc_del1_dop(t_parser *parser, int *k, char **search, int *j)
{
	(*search)[*j] = parser->crtline[*k];
	*k += 1;
	*j += 1;
}

void	ft_check_env3_dop(t_parser *parser, char *envp, char **search, int *m)
{
	ft_skok_tam1(envp, ft_strlen((*search)), parser, m);
	free((*search));
}
