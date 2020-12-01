/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcesar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:51:24 by qcesar            #+#    #+#             */
/*   Updated: 2020/11/21 16:06:44 by qcesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myprintf.h"

static int		length_counter(unsigned int n)
{
	if (n > 9)
		return (1 + length_counter(n / 10));
	else
		return (1);
}

char			*ft_uitoa(unsigned int n, t_list *lst)
{
	int		length;
	char	*str;

	length = length_counter(n);
	if (!(str = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	str[length--] = '\0';
	while (length != -1)
	{
		str[length] = n % 10 + '0';
		n = n / 10;
		length--;
	}
	lst->sign = 1;
	return (str);
}
