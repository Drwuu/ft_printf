/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:44:47 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/11 16:41:50 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_datas(t_datas *datas)
{
	datas->dot = 0;
	datas->id = 0;
	datas->minus = 0;
	datas->star = 0;
	datas->zero = 0;
	datas->str = NULL;
}

t_list		*ft_no_conv(char *str, t_list **list)
{
	t_datas	*datas;
	t_list	*new_el;

	if (!(datas = ft_calloc(sizeof(*datas), 1)))
		return (NULL);
	if (!(datas->str = str))
		return (NULL);
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	return (new_el);
}

t_list		*ft_conv_char(char c, char *str, t_list **list)
{
	t_datas	*datas;
	t_list	*new_el;

	if (!(datas = ft_calloc(sizeof(*datas), 1)))
		return (NULL);
	if (c == '%')
	{
		if (!(datas->str = ft_char('%')))
			return (NULL);
	}
	else if (c == 'c')
		if (!(datas->str = str))
			return (NULL);
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	return (new_el);
}
