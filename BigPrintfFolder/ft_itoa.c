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

static int		length_counter(int n)
{
	if (n > 9)
		return (1 + length_counter(n / 10));
	else
		return (1);
}

static int		sign_checker(int n, t_list *lst)
{
	if (n >= 0)
	{
		lst->sign = 1;
		return (0);
	}
	else
	{
		lst->sign = -1;
		return (1);
	}
}

char			*ft_itoa(int n, t_list *lst)
{
	int		length;
	char	*str;
	int		sign;

	if (n == -2147483648)
	{
		lst->sign = -1;
		return (ft_strdup("2147483648"));
	}
	sign = sign_checker(n, lst);
	length = sign ? length_counter(-n) : length_counter(n);
	if (!(str = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	n = sign ? (-n) : n;
	str[length--] = '\0';
	while (length != -1)
	{
		str[length] = n % 10 + '0';
		n = n / 10;
		length--;
	}
	return (str);
}
