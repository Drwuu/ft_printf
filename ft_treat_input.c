/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:54:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/03 16:14:28 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		proccess_treatment(const char *input, int *i, t_list **lst,
va_list ap)
{
	int		start;
	t_datas	*datas;

	start = *i;
	while (input[*i])
	{
		*i = ft_chr_index(input, '%', *i);
		if (*i - start > 0)
			if (!(*lst = get_no_conv(ft_substr(input, start, *i - start), lst)))
				return (-1);
		if (!(datas = get_flags(input, i, ap)))
			return (-1);
		if ((get_conversions(input[*i], &datas, lst, ap)) < 0)
			return (-1);
		if (input[*i] == '\0')
			return (*i);
		*i += 1;
		start = *i;
	}
	return (*i);
}

t_list			*treat_input(const char *input, t_list **lst, va_list ap)
{
	int			i;
	int			j;
	t_list		*f_elem;

	i = 0;
	i = ft_chr_index(input, '%', i);
	if (!(*lst = get_no_conv(ft_substr(input, 0, i), lst)))
		return (NULL);
	f_elem = *lst;
	if ((j = proccess_treatment(input, &i, lst, ap)) < 0)
		return (NULL);
	if (input[j])
		if (!(*lst = get_no_conv(ft_substr(input, j, i), lst)))
			return (NULL);
	return (f_elem);
}
