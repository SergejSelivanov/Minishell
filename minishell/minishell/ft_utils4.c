/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:27:29 by festermo          #+#    #+#             */
/*   Updated: 2020/12/21 14:45:52 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_fill(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(src))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == NULL || dst == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(src))
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		ft_fill(dst, src);
	}
	return (ft_strlen(src));
}

size_t			ft_strlen(const char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int				ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i] &&
	((unsigned char)str1[i] == (unsigned char)str2[i]) && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

char			*ft_strnstr(const char *big, const char *little, size_t k)
{
	size_t pos;
	size_t i;

	if (!big)
		return (NULL);
	if (!little[0])
		return ((char *)big);
	pos = 0;
	while (big[pos] && pos < k)
	{
		if (big[pos] == little[0])
		{
			i = 1;
			while (little[i] && big[pos + i] == little[i] && (pos + i) < k)
				i++;
			if (little[i] == '\0')
				return ((char *)big + pos);
		}
		pos++;
	}
	return (NULL);
}
