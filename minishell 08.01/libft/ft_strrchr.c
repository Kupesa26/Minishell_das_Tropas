/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:00:40 by akupesa           #+#    #+#             */
/*   Updated: 2024/05/22 15:03:52 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	if (*s == (char)c)
		ptr = (char *)s;
	while (*s++)
		if (*s == (char)c)
			ptr = (char *)s;
	return (ptr);
}
