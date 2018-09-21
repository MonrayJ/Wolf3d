/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 06:16:12 by mjacobs           #+#    #+#             */
/*   Updated: 2018/06/06 15:05:01 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	if ((!(*s1) || !(*s2)) && n == 0)
		return (0);
	if (n == 0)
		return (0);
	sa = (unsigned char*)s1;
	sb = (unsigned char*)s2;
	i = 0;
	while (sa[i] == sb[i] && sa[i] && sb[i] && i < n - 1)
		i++;
	return (sa[i] - sb[i]);
}
