/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:44:47 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/16 15:56:36 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*no_conv(char *s, t_list **list)
{
	t_datas	*datas;
	t_list	*new_el;

	if (!s)
		return (NULL);
	if (!(datas = ft_calloc(sizeof(*datas), 1)))
		return (NULL);
	if (!(datas->str = s))
		return (NULL);
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	return (new_el);
}

t_list		*conv_char(char c, char *s, t_list **list)
{
	t_datas	*datas;
	t_list	*new_el;

	if (!s)
		return (NULL);
	if (!(datas = ft_calloc(sizeof(*datas), 1)))
		return (NULL);
	if (c == '%')
	{
		free(s);
		if (!(datas->str = ft_char('%')))
			return (NULL);
	}
	else if (c == 'c')
		if (!(datas->str = s))
			return (NULL);
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	return (new_el);
}

t_list		**conv_digits(char c, t_list **list, va_list ap)
{
	t_list	**lst;
	char	*nb;

	if (c == 'u')
		if (!(nb = ft_itoa_ui(va_arg(ap, unsigned int))))
			return (NULL);
	if (c == 'x')
		if (!(nb = ft_itoa_base("0123456789abcdef", va_arg(ap, unsigned int))))
			return (NULL);
	if (c == 'X')
		if (!(nb = ft_itoa_base("0123456789ABCDEF", va_arg(ap, unsigned int))))
			return (NULL);
	if (c == 'd' || c == 'i')
		if (!(nb = ft_itoa(va_arg(ap, int))))
			return (NULL);
	if (!(lst = fill_list(list, nb, ft_strdup)))
		return (NULL);
	free(nb);
	return (lst);
}
