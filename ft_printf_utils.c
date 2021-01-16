/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:05:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/16 17:24:11 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_datas(t_datas *datas)
{
	datas->str = NULL;
	datas->dot = -1;
	datas->field = -1;
	datas->minus = -1;
	datas->star = -1;
	datas->zero = -1;
}

int		free_error(t_list *lst, va_list ap)
{
	t_list *f_elem;

	f_elem = lst;
	while (lst)
	{
		free(((t_datas *)lst->content)->str);
		lst = lst->next;
	}
	ft_lstclear(&f_elem, free);
	va_end(ap);
	return (-1);
}

char	*collect_digits_seq(const char *digits, int *start)
{
	char	*dig_seq;
	int		size;
	int		save;
	int		i;

	if (!(ft_isdigit(digits[*start])))
		return (NULL);
	save = *start;
	size = 0;
	while (digits[save] && ft_isdigit(digits[save++]))
		size++;
	if (!(dig_seq = malloc(sizeof(*dig_seq) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		dig_seq[i] = digits[*start];
		*start += 1;
		i++;
	}
	return (dig_seq);
}

t_list	**fill_list(t_list **list, char *str, char *f(const char *))
{
	t_datas	*datas;
	t_list	*new_el;

	if (!str)
		return (NULL);
	if (!(datas = ft_calloc(sizeof(*datas), 1)))
		return (NULL);
	if (!(datas->str = f(str)))
		return (NULL);
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	return (list);
}
