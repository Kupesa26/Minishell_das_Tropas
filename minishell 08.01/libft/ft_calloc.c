/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:59:56 by akupesa           #+#    #+#             */
/*   Updated: 2024/05/22 16:00:11 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		result;

	ptr = NULL;
	result = nmemb * size;
	if (!nmemb || !size || !(nmemb != result / size))
		ptr = malloc(result);
	if (ptr)
		ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
