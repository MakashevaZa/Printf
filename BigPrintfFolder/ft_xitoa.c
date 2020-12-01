/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcesar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:31:47 by qcesar            #+#    #+#             */
/*   Updated: 2020/11/24 11:31:53 by qcesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myprintf.h"

static int		length_counter(unsigned int n)
{
	if (n > 15)
		return (1 + length_counter(n / 16));
	else
		return (1);
}

char			*ft_xitoa(char basex, unsigned int n, t_list *lst)
{
	int		length;
	char	*str;
	char *base1;

    base1 = "0123456789abcdef";
	if (basex == 'X')
		base1 = ft_strdup("0123456789ABCDEF");
	length = length_counter(n);
	if (!(str = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	str[length--] = '\0';
	while (length != -1)
	{
		str[length] = base1[n % 16];
		n = n / 16;
		length--;
	}
	lst->sign = 1;
	return (str);
}