/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:26:17 by mjacobs           #+#    #+#             */
/*   Updated: 2018/05/30 17:01:45 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	len2;

	if (!*needle)
		return ((char *)hay);
	len2 = ft_strlen(needle);
	while (*hay && len-- >= len2)
	{
		if (*hay == *needle && ft_memcmp(hay, needle, len2) == 0)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}
