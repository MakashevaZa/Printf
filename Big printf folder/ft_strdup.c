/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcesar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:15:42 by qcesar            #+#    #+#             */
/*   Updated: 2020/11/18 16:39:23 by qcesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myprintf.h"

char	*ft_strdup(const char *str)
{
	char *result;

	result = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (result)
		ft_strlcpy(result, str, ft_strlen(str) + 1);
	else
		return (NULL);
	return (result);
}
