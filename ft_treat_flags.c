/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:59:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/23 18:08:26 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		treat_field(t_list *lst)
{
	int		i;
	int		size;
	t_datas	*datas;

	datas = lst->content;
	if (datas->field > -1)
	{

		size = datas->field - ft_strlen(datas->str);
		i = 0;
		while (i++ < size)
		{
			if (datas->zero > -1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
	}
}