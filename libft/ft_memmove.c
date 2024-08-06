/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:05:19 by anamedin          #+#    #+#             */
/*   Updated: 2024/02/19 15:14:59 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (src < dst)
	{
		while (len-- > 0)
			dst_ptr[len] = src_ptr[len];
	}
	else
	{
		while (len-- > 0)
			*dst_ptr++ = *src_ptr++;
	}
	return (dst);
}
