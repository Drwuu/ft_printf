/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:05:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/13 18:16:43 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		**fill_list(t_list **list, char *str, char *f(const char *))
{
	t_datas	*datas;
	t_list	*new_el;

	if (!(datas = ft_calloc(sizeof(*datas), 1)))
		return (NULL);
	if (!(datas->str = f(str)))
		return (NULL);
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	return (list);
}
