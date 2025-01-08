/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:13:41 by akupesa           #+#    #+#             */
/*   Updated: 2024/05/17 10:23:52 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = (char *)malloc (sizeof(char) * (len1 + len2 + 1));
	if (strjoin == NULL)
		return (NULL);
	ft_memcpy(strjoin, s1, len1);
	ft_memcpy(strjoin + len1, s2, len2 + 1);
	return (strjoin);
}
