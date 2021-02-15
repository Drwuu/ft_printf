/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:44:47 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/15 12:11:23 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	**get_digits(char c, t_datas *datas, t_list **list, va_list ap)
{
	t_list	**lst;
	char	*nb;

	datas->d_conv = 1;
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
	if (!(lst = fill_list(datas, list, nb, ft_strdup)))
		return (NULL);
	free(nb);
	return (lst);
}

static t_list	*get_char(char c, va_list ap, t_datas *datas, t_list **list)
{
	t_list	*new_el;

	if (c == '%')
	{
		if (!(datas->str = ft_char_to_str('%')))
			return (NULL);
	}
	else
	{
		if (!(datas->str = ft_char_to_str(va_arg(ap, int))))
			return (NULL);
	}
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	datas->c_conv = 1;
	return (new_el);
}

int				get_conversions(char c, t_datas **datas, t_list **lst, \
va_list ap)
{
	char	*p;

	if (c == 's')
		if (!(lst = fill_list(*datas, lst, va_arg(ap, char *), ft_strdup)))
			return (-1);
	if (c == 'p')
	{
		p = ft_itoa_base("0123456789abcdef", va_arg(ap, unsigned long));
		(*datas)->p_conv = 1;
		if (!(lst = fill_list(*datas, lst, p, ft_strdup)))
			return (-1);
		free(p);
	}
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		if (!(lst = get_digits(c, *datas, lst, ap)))
			return (-1);
	if (c == '%' || c == 'c')
		if (!(*lst = get_char(c, ap, *datas, lst)))
			return (-1);
	(c == '\0') ? free(*datas) : 0;
	return (1);
}

t_list			*get_no_conv(char *s, t_list **list)
{
	t_list	*new_el;
	t_datas *datas;

	if (!s)
		return (NULL);
	if (!(datas = init_datas()))
		return (NULL);
	if (!((datas)->str = s))
		return (NULL);
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	return (new_el);
}
