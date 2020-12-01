/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcesar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:52:58 by qcesar            #+#    #+#             */
/*   Updated: 2020/11/10 21:16:12 by qcesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myprintf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		result;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	result = ft_strlen(src);
	if (size != 0)
	{
		while (size - 1 > 0 && *s)
		{
			*d++ = *s++;
			size--;
		}
		*d = '\0';
	}
	return (result);
}
