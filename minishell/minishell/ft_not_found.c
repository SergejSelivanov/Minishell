/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_found.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:08:25 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 19:10:00 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_not_found(char *str, t_parser *parser, int fd)
{
	int		i;
	char	*msg;

	i = 0;
	while (ft_strchr(" ", *str))
	{
		if (ft_strchr(" ", *(str + 1)))
			str++;
		else
			break ;
	}
	while (str[i] && str[i] != ' ')
		i++;
	msg = (char *)malloc(sizeof(char) * (i + 2));
	msg[i + 1] = '\0';
	ft_strlcpy(msg, str, i + 1);
	write(fd, "minishell: ", 12);
	write(fd, msg, ft_strlen(msg));
	write(fd, ": command not found\n", 20);
	free(msg);
	parser->dollar = 127;
	return (127);
}
