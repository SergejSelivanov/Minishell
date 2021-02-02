/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:47:37 by wjena             #+#    #+#             */
/*   Updated: 2020/12/23 15:08:41 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_zikl(char **search, char *envp, int *kk)
{
	if (ft_strncmp((*search), envp, ft_strlen((*search))) == 0)
	{
		*kk = ft_strlen((*search));
		free((*search));
		return (1);
	}
	return (0);
}

int		ft_zikl1(char **search, int *kk, char *envp)
{
	if (ft_strncmp((*search), envp, ft_strlen((*search))) == 0)
	{
		*kk = ft_strlen((*search));
		free((*search));
		return (1);
	}
	return (0);
}

void	ft_check_qual1(char **search, t_parser *parser, int *kk)
{
	if (ft_strlen((*search)) == 1 && (*search)[0] == '='
		&& parser->params.flag_govna == 0)
	{
		*kk += 1;
	}
	parser->params.flag_govna = 0;
	free((*search));
}

int		ft_zikl3(t_parser *parser, char **search, char *envp, int *m)
{
	if (ft_strncmp((*search), envp, ft_strlen((*search))) == 0)
	{
		ft_skok_tam1(envp, ft_strlen((*search)), parser, m);
		free((*search));
		parser->flap_sp1 = 0;
		return (1);
	}
	return (0);
}

void	ft_check_qual4(t_parser *parser, char **search, int *m)
{
	parser->flap_sp1 = 1;
	if (ft_strlen((*search)) == 1 && (*search)[0] == '='
		&& parser->params.flag_govna == 0)
	{
		parser->params.commands[parser->lenlen][*m] = '$';
		*m += 1;
	}
	parser->params.flag_govna = 0;
	free((*search));
}
