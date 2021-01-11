/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:54:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/11 18:06:55 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //to remove

static void		print_final_str(t_list *lst)
{
	while (lst)
	{
		ft_putstr_fd(((t_datas *)lst->content)->str, 1);
		free(((t_datas *)lst->content)->str);
		lst = lst->next;
	}
}

static t_list	*treat_input(const char *input, va_list ap)
{
	int			i;
	int			start;
	t_list		*lst;
	t_list		*f_elem;
	
	i = 0;
	lst = NULL;
	if (!((lst = ft_no_conv(ft_substr(input, 0, (i = ft_chr_index(input, '%', i))), &lst))))
		return (NULL);
	start = i;
	f_elem = lst;
	while ((i = ft_chr_index(input, '%', i)) >= 0 && input[i])
	{
		if (!((lst = ft_no_conv(ft_substr(input, start, i - start), &lst))))
			return (NULL);
		/* if (input[i + 1] == 's')
			if (!((lst = ft_t_str(input, &start, &i))))
				return (NULL); */
		if (input[i + 1] == '%' || input[i + 1] == 'c')
			if (!((lst = ft_conv_char(input[++i], ft_char(va_arg(ap, int)), &lst))))
				return (NULL);
		i++;
		start = i;
	}
	if (!((lst = ft_no_conv(ft_substr(input, start++, ++i), &lst))))
		return (NULL);
	return (f_elem);
}

int				ft_printf(const char *input, ...)
{
	va_list		ap;
	t_list		*lst;

	va_start(ap, input);
	if(!(lst = treat_input(input, ap)))
		return (-1);
	print_final_str(lst);
	ft_lstclear(&lst, free);
	va_end(ap);
	return (0);
}
