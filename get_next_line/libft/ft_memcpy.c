/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:35:31 by mjacobs           #+#    #+#             */
/*   Updated: 2018/05/21 17:23:12 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *s1;
	char *s2;

	if (n == 0 || dst == src)
		return (dst);
	s1 = (char*)dst;
	s2 = (char*)src;
	while (--n)
		*s1++ = *s2++;
	*s1 = *s2;
	return (dst);
}
