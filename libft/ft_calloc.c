/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:42:02 by ilnassi           #+#    #+#             */
/*   Updated: 2024/12/23 13:18:01 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, nmemb * size);
	return (p);
}
