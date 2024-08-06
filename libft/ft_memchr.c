/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:32:24 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/16 18:45:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	unsigned char		ch;
	const unsigned char	*str;

	ch = c;
	str = s;
	i = 0;
	while (n > 0)
	{
		if (str[i] == ch)
			return ((void *)str + i);
		i++;
		n--;
	}
	return (NULL);
}
