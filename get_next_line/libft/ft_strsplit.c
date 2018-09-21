/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 10:41:00 by mjacobs           #+#    #+#             */
/*   Updated: 2018/06/28 10:41:04 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strclen(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int		ft_wd_cnt(const char *str, char c)
{
	int				i;
	int				word;
	int				count;

	i = 0;
	count = 1;
	word = 1;
	while (str[i])
	{
		if (str[i] != c)
			word = 1;
		else if (word == 1)
		{
			count += 1;
			word = 0;
		}
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i;
	int		row;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	row = ft_wd_cnt(s, c);
	if (!(fresh = ((char**)malloc(sizeof(*fresh) * (row + 1)))))
		return (NULL);
	while (row--)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_strclen(s, c);
		if (len == 0)
			break ;
		if (!(fresh[i] = ft_strsub(s, 0, len)))
			return (NULL);
		s = s + ft_strclen(s, c);
		i++;
	}
	fresh[i] = NULL;
	return (fresh);
}
