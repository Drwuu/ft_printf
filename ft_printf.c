/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:54:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/27 16:37:27 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		free_error(t_list *lst, va_list ap)
{
	t_list	*f_elem;
	t_datas	*datas;

	f_elem = lst;
	while (lst)
	{
		datas = lst->content;
		free(datas->str);
		lst = lst->next;
	}
	ft_lstclear(&f_elem, free);
	va_end(ap);
	return (-1);
}

static int		print_flags(t_list *lst)
{
	char	*str;
	int		ret;
	
	if (((t_datas *)lst->content)->field >= 0 && \
	((t_datas *)lst->content)->minus == -1)
		display_field(lst, 1);
	if ((ret = display_dot(lst, &str)) == -1)
		return (-1);
	//dprintf(1, "disp dot = %d\n", ret);
	if (ret)
	{
		ft_putstr_fd(str, 1);
		free(str);
		return (1);
	}
	else
		return (0);
}

static int		print_final_str(t_list *lst)
{
	t_datas	*datas;
	int		ret;

	while (lst)
	{
		datas = lst->content;
		if (datas->minus == -1)
		{
			if ((ret = print_flags(lst)) < 0)
				return (-1);
			if (ret == 0)
				ft_putstr_fd(datas->str, 1);
		}
		else
		{
			(datas->dot == -1) ? ft_putstr_fd(datas->str, 1) : 0;
			if (print_flags(lst) < 0)
				return (-1);
		}
		(datas->field < 0 && datas-> minus == 0) ? display_field(lst, 0) : 0;
		free(datas->str);
		lst = lst->next;
	}
	return (0);
}

int				ft_printf(const char *input, ...)
{
	va_list		ap;
	t_list		*lst;

	lst = NULL;
	va_start(ap, input);
	if (!(lst = treat_input(input, &lst, ap)))
		return (free_error(lst, ap));
	if (print_final_str(lst) < 0)
		return (free_error(lst, ap));
	ft_lstclear(&lst, free);
	va_end(ap);
	return (0);
}
