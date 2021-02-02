/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjena <wjena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:40:59 by festermo          #+#    #+#             */
/*   Updated: 2020/12/21 14:41:26 by wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*ft_skip(const char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static int			ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		s = ft_skip(s, c);
		if (*s != '\0')
		{
			while (*s != '\0' && *s != c)
				s++;
			count++;
		}
	}
	return (count);
}

static int			ft_memfree(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

static int			ft_fill_str(char const *s, char c, char **str, int count)
{
	char	*sstr;
	int		i;
	int		m;

	m = 0;
	while (count > 0)
	{
		s = ft_skip(s, c);
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (!(sstr = (char *)malloc(sizeof(char) * (i) + 1)))
			return (ft_memfree(str));
		ft_strlcpy(sstr, s, i + 1);
		str[m] = sstr;
		s += i;
		count--;
		m++;
	}
	str[m] = NULL;
	return (1);
}

char				**ft_split(char const *s, char c)
{
	char	**str;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (ft_fill_str(s, c, str, count) == 0)
		return (NULL);
	return (str);
}
