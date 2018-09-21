/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 06:52:30 by mjacobs           #+#    #+#             */
/*   Updated: 2018/05/30 17:05:33 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int snap;
	int n;

	n = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str == '0')
		str++;
	snap = 0;
	i = 0;
	while (*str >= '0' && *str <= '9' && *str)
	{
		i = (i * 10) + (*str++ - '0');
		if (snap > 18)
			return ((n == -1) ? 0 : -1);
		snap++;
	}
	return (i * n);
}
