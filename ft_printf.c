/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:54:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/23 18:14:48 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		free_datas(t_datas *datas)
{
	free(datas->str);
}

static int		free_error(t_list *lst, va_list ap)
{
	t_list *f_elem;

	f_elem = lst;
	while (lst)
	{
		free(lst->content);
		lst = lst->next;
	}
	ft_lstclear(&f_elem, free);
	va_end(ap);
	return (-1);
}

static void		print_final_str(t_list *lst)
{
	t_datas *datas;

	while (lst)
	{
		datas = lst->content;
		if (datas->minus == -1)
			treat_field(lst);
		ft_putstr_fd(datas->str, 1);
		if (datas->minus > -1)
			treat_field(lst);
		free_datas(lst->content);
		lst = lst->next;
	}
}

int				ft_printf(const char *input, ...)
{
	va_list		ap;
	t_list		*lst;

	lst = NULL;
	va_start(ap, input);
	if (!(lst = treat_input(input, &lst, ap)))
		return (free_error(lst, ap));
	print_final_str(lst);
	ft_lstclear(&lst, free);
	va_end(ap);
	return (0);
}
