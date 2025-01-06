/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:22:40 by akupesa           #+#    #+#             */
/*   Updated: 2024/05/22 15:33:26 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	len = ft_min(ft_strlen(haystack), len);
	i = 0;
	while (i + ft_strlen(needle) <= len)
	{
		if (!ft_memcmp(haystack + i, needle, ft_strlen(needle)))
			return ((char *)haystack + i);
		++i;
	}
	return (NULL);
}
