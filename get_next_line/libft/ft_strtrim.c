/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:17:45 by mjacobs           #+#    #+#             */
/*   Updated: 2018/06/28 11:17:51 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_whitesp(int c)
{
	return (c == 32 || (c >= '\t' && c <= '\r'));
}

char			*ft_strtrim(char const *s)
{
	char	*r;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	k = ft_strlen(s);
	j = 0;
	i = 0;
	while (s[i] && ft_whitesp(s[i]))
		i++;
	while (s[k - 1] && ft_whitesp(s[k - 1]))
		k--;
	if (i > k)
		return (ft_strnew(0));
	if (!(r = ft_strnew(k - i)))
		return (NULL);
	while (i < k)
		r[j++] = s[i++];
	return (r);
}
