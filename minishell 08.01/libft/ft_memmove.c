/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:56:41 by akupesa           #+#    #+#             */
/*   Updated: 2024/05/22 17:14:59 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*sr;
	char	*ds;

	i = len;
	ds = (char *)dst;
	sr = (char *)src;
	if (dst == src)
		return (dst);
	else if (ds > sr)
	{
		while (i > 0)
		{
			i--;
			ds[i] = sr[i];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (ds);
}
