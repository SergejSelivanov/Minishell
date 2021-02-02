/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:04:56 by festermo          #+#    #+#             */
/*   Updated: 2020/12/24 14:11:13 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(char *str, t_parser *parser)
{
	int		flag_echo;
	int		i;
	int		len;
	char	*str_print;

	len = ft_strlen(str) - 5;
	i = 0;
	flag_echo = 0;
	if (!(ft_strncmp("echo", str, 4)) && !(*(str + 4)))
	{
		write(1, "\n", 1);
		return (1);
	}
	else if (!(ft_strncmp("echo", str, 4)) && (*(str + 4) == ' '))
	{
		i = ft_echo_skip_flags(&str, len, &flag_echo);
		str_print = ft_strdup(str + i);
		write(1, str_print, ft_strlen(str_print));
		if (flag_echo == 0)
			write(1, "\n", 1);
		parser->dollar = 0;
		free(str_print);
		return (1);
	}
	return (0);
}

int		ft_echo_skip_flags(char **str, int len, int *flag_echo)
{
	int i;

	i = 0;
	*str += 5;
	if (ft_find_flag(*str, i))
		while ((*str)[i] && i <= len)
		{
			if ((*str)[i] == '-')
			{
				if (!(ft_strncmp("-n", (*str) + i, 2)) && ((*str)[i + 2] == ' '
				|| i + 2 >= len))
				{
					i += 2;
					*flag_echo = 1;
				}
				else
					break ;
			}
			else if ((*str)[i] == ' ')
				i++;
			else
				break ;
		}
	return (i);
}

int		ft_find_flag(char *str, int i)
{
	int ret;

	ret = 0;
	while (str[i])
	{
		if (!(ft_strncmp("-n", str + i, 2)) && str[i] != ' ' &&
		(str[i + 2] == ' ' || !(str[i + 2])))
		{
			ret = 1;
			break ;
		}
		i++;
	}
	return (ret);
}
