/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:18:04 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 17:18:49 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export3(char **strings, int j, t_parser *parser)
{
	write(1, "minishell: export: `", 20);
	write(1, strings[j], ft_strlen(strings[j]));
	write(1, "': not a valid identifier\n", 26);
	parser->dollar = 1;
}
