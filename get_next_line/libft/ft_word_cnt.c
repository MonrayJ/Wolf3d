/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_cnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:57:13 by mjacobs           #+#    #+#             */
/*   Updated: 2018/06/18 11:57:19 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_cnt(const char *str, char c)
{
	int	i;
	int	word;
	int	count;

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
