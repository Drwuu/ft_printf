/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:54:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/30 16:53:59 by lwourms          ###   ########lyon.fr   */
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

static int		print_flags(t_list *lst, int *charNbr)
{
	char	*str;
	int		ret;
	
	if (((t_datas *)lst->content)->field >= 0 && \
	((t_datas *)lst->content)->minus == -1)
		display_field(lst, 1, charNbr);
	if ((ret = display_dot(lst, &str, charNbr)) == -1)
		return (-1);
	if (ret)
	{
		ft_putstr_fd(str, 1);
		*charNbr += ft_strlen((const char *)str);
		free(str);
		return (1);
	}
	else
		return (0);
}

static int		print_minus(t_list *lst, t_datas *datas, int *charNbr)
{
	int		ret;

	if (datas->minus == -1)
	{
		if ((ret = print_flags(lst, charNbr)) < 0)
			return (-1);
		if (ret == 0)
		{
			ft_putstr_fd(datas->str, 1);
			*charNbr += ft_strlen((const char *)datas->str);
		}
	}
	else
	{
		if (datas->dot == -1)
		{
			ft_putstr_fd(datas->str, 1);
			*charNbr += ft_strlen((const char *)datas->str);
		}
		if (print_flags(lst, charNbr) < 0)
			return (-1);
	}
	if (datas->c_conv && !datas->str[0])
		ft_putchar_fd('\0', 1);
	return (0);
}

static int		print_final_str(t_list *lst, int *charNbr)
{
	t_datas	*datas;

	while (lst)
	{
		datas = lst->content;
		if (print_minus(lst, datas, charNbr) < 0)
			return (-1);
		(datas->field < 0 || datas->minus == 0) ? \
		display_field(lst, 0, charNbr) : 0;
		free(datas->str);
		lst = lst->next;
	}
	return (0);
}

int				ft_printf(const char *input, ...)
{
	va_list		ap;
	t_list		*lst;
	int			charNbr;

	lst = NULL;
	charNbr = 0;
	va_start(ap, input);
	if (!(lst = treat_input(input, &lst, ap)))
		return (free_error(lst, ap));
	if (print_final_str(lst, &charNbr) < 0)
		return (free_error(lst, ap));
	ft_lstclear(&lst, free);
	va_end(ap);
	return (charNbr);
}
