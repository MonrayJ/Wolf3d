/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 08:01:17 by mjacobs           #+#    #+#             */
/*   Updated: 2018/05/29 18:12:20 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	k = ft_strlen(needle);
	if (k == 0)
		return ((char*)hay);
	while (hay[i])
	{
		j = 0;
		while (needle[j] == hay[i + j])
		{
			if (j == k - 1)
				return ((char*)&hay[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
