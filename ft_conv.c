/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:44:47 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/23 15:19:56 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	**conv_digits(char c, t_datas *datas, t_list **list, va_list ap)
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
	if (!(lst = fill_list(datas, list, nb, ft_strdup)))
		return (NULL);
	free(nb);
	return (lst);
}

static t_list	*conv_char(char c, t_datas *datas, char *s, t_list **list)
{
	t_list	*new_el;

	if (!s)
		return (NULL);
	if (c == '%')
	{
		free(s);
		if (!(datas->str = ft_char_to_str('%')))
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

int				convert_process(char c, t_datas **datas, t_list **lst, \
va_list ap)
{
	if (c == 's')
		if (!(lst = fill_list(*datas, lst, va_arg(ap, char *), ft_strdup)))
			return (-1);
	if (c == 'p') // not usable
		if (!(lst = fill_list(*datas, lst, ft_itoa_base("0123456789abcdef", \
		va_arg(ap, unsigned int)), ft_strdup)))
			return (-1);
	if (c == 'd' || c == 'i' || \
	c == 'u' || c == 'x' || c == 'X')
		if (!(lst = conv_digits(c, *datas, lst, ap)))
			return (-1);
	if (c == '%' || c == 'c')
		if (!(*lst = conv_char(c, *datas, ft_char_to_str(va_arg(ap, int)), \
		lst)))
			return (-1);
	return (1);
}

t_list			*no_conv(char *s, t_list **list)
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

int				is_conv(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || \
	c == 'x' || c == 'X' || c == 'c')
		return (1);
	return (0);
}
