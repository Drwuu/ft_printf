/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:54:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/13 19:58:36 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //to remove

static int	free_error(t_list *lst, va_list ap)
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

static void		print_final_str(t_list *lst)
{
	while (lst)
	{
		ft_putstr_fd(((t_datas *)lst->content)->str, 1);
		free(((t_datas *)lst->content)->str);
		lst = lst->next;
	}
}

static int	convert(const char *input, int *i, t_list **lst, va_list ap)
{
	if (input[*i + 1] == 's' || input[*i + 1] == 'p')
	{
		if (input[*i + 1] == 'p')
		{
			dprintf(1, "BOUUUUUUHH\n");
			if (!(lst = fill_list(lst, ft_itoa_base("0123456789abcdef", va_arg(ap, unsigned int)), ft_strdup)))
				return (-1);
		}
		else
			if (!(lst = fill_list(lst, va_arg(ap, char *), ft_strdup)))
				return (-1);
		*i += 1;
	}
	else if (input[*i + 1] == 'd' || input[*i + 1] == 'i' ||
	input[*i + 1] == 'u' || input[*i + 1] == 'x' || input[*i + 1] == 'X')
	{
		if (!((lst = ft_conv_digits(input[*i + 1], lst, ap))))
			return (-1);
		*i += 1;
	}
	else if (input[*i + 1] == '%' || input[*i + 1] == 'c')
		if (!((*lst = ft_conv_char(input[++*i], ft_char(va_arg(ap, int)), lst))))
			return (-1);
	return (1);
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
		if (i - start > 0)
			if (!((lst = ft_no_conv(ft_substr(input, start, i - start), &lst))))
				return (NULL);
		if (!(convert(input, &i, &lst, ap)))
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
		return (free_error(lst, ap));
	print_final_str(lst);
	ft_lstclear(&lst, free);
	va_end(ap);
	return (0);
}
