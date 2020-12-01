/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcesar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:07:33 by qcesar            #+#    #+#             */
/*   Updated: 2020/11/10 20:49:10 by qcesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}