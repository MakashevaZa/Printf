/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcesar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:05:36 by qcesar            #+#    #+#             */
/*   Updated: 2020/11/14 11:38:46 by qcesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myprintf.h"

t_list	*ft_lstnew(void)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->width = -1;
	lstnew->filler = ' ';
	lstnew->precision = -1;
	lstnew->align = 'r';
	lstnew->ispres = 0;
	lstnew->sign = 0;
	return (lstnew);
}
