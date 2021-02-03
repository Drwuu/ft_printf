/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:54:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/03 16:26:43 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	free_error(t_list *lst, va_list ap)
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
	//dprintf(1, "ERROR\n");
	return (-1);
}

int			ft_printf(const char *input, ...)
{
	va_list		ap;
	t_list		*lst;
	int			charNbr;

	lst = NULL;
	charNbr = 0;
	va_start(ap, input);
	if (!(lst = treat_input(input, &lst, ap)))
		return (free_error(lst, ap));
	print_process(lst, &charNbr);
	ft_lstclear(&lst, free);
	va_end(ap);
	return (charNbr);
}
