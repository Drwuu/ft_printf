/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:54:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/16 17:35:00 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_final_str(t_list *lst)
{
	while (lst)
	{
		ft_putstr_fd(((t_datas *)lst->content)->str, 1);
		free(((t_datas *)lst->content)->str);
		lst = lst->next;
	}
}

static int		convert_process(const char *input, int *i, t_list **lst, \
va_list ap)
{
	if (input[*i + 1] == 's')
		if (!(lst = fill_list(lst, va_arg(ap, char *), ft_strdup)))
			return (-1);
	if (input[*i + 1] == 'p')
		if (!(lst = fill_list(lst, ft_itoa_base("0123456789abcdef", \
		va_arg(ap, unsigned int)), ft_strdup)))
			return (-1);
	if (input[*i + 1] == 'd' || input[*i + 1] == 'i' || \
	input[*i + 1] == 'u' || input[*i + 1] == 'x' || input[*i + 1] == 'X')
		if (!(lst = conv_digits(input[*i + 1], lst, ap)))
			return (-1);
	if (input[*i + 1] == '%' || input[*i + 1] == 'c')
		if (!(*lst = conv_char(input[*i + 1], ft_char(va_arg(ap, int)), lst)))
			return (-1);
	*i += 1;
	return (1);
}

static t_datas	*prepare_input(const char *input, t_list **lst, int *i,
int *start)
{
	t_datas		*flags;
	
	if (!(*lst = no_conv(ft_substr(input, 0, \
	(*i = ft_chr_index(input, '%', *i))), lst)))
		return (NULL);
	*start = *i;
	if (get_flags(input, i, &flags) < 0)
		return (NULL);
	return (flags);
}

static t_list	*treat_input(const char *input, t_list **lst, va_list ap)
{
	int			i;
	int			start;
	t_list		*f_elem;
	t_datas		*flags;

	i = 0;
	if (!(flags = prepare_input(input, lst, &i, &start)))
		return (NULL);
	f_elem = *lst;
	while ((i = ft_chr_index(input, '%', i)) && input[i])
	{
		if (i - start > 0)
			if (!(*lst = no_conv(ft_substr(input, start, i - start), lst)))
				return (NULL);
		if ((convert_process(input, &i, lst, ap)) < 0)
			return (NULL);
		i++;
		start = i;
	}
	if (!(*lst = no_conv(ft_substr(input, start++, ++i), lst)))
		return (NULL);
	free (flags);
	return (f_elem);
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
