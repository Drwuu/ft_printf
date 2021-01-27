/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:05:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/27 15:47:36 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_datas	*init_datas(void)
{
	t_datas		*datas;

	if (!(datas = ft_calloc(sizeof(*datas), 1)))
		return (NULL);
	datas->str = NULL;
	datas->dot = -1;
	datas->field = -1;
	datas->is_field = 0;
	datas->minus = -1;
	datas->star = -1;
	datas->zero = -1;
	datas->d_conv = 0;
	return (datas);
}

char	*collect_digits_seq(const char *digits, int start)
{
	char	*dig_seq;
	int		size;
	int		save;
	int		i;

	save = start;
	size = 0;
	while (digits[save] && ft_isdigit(digits[save++]))
		size++;
	if (!(dig_seq = malloc(sizeof(*dig_seq) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		dig_seq[i] = digits[start];
		start++;
		i++;
	}
	dig_seq[i] = '\0';
	return (dig_seq);
}

t_list	**fill_list(t_datas *datas, t_list **list, char *str, \
char *f(const char *))
{
	t_list	*new_el;

	if (!str)
		return (NULL);
	if (!(datas->str = f(str)))
		return (NULL);
	if (!(new_el = ft_lstnew(datas)))
		return (NULL);
	ft_lstadd_back(list, new_el);
	return (list);
}
