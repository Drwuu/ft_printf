/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:59:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/15 12:19:24 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_char(int size, char c, int *char_nbr)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		ft_putchar_fd(c, 1);
		*char_nbr += 1;
	}
}

void		print_zeros(int size, t_datas *datas, int *char_nbr)
{
	if (datas->str[0] == '-')
	{
		print_char(1, '-', char_nbr);
		*char_nbr -= 1;
	}
	datas->zero_prt = 1;
	print_char(size, '0', char_nbr);
}

void		print_field(int size, t_datas *datas, int *char_nbr)
{
	if (!datas->zero || (datas->zero && datas->is_dot && datas->dot >= 0))
		print_char(size, ' ', char_nbr);
}

void		print_dot(int dot, t_datas *datas, int *char_nbr)
{
	int i;
	int	str_size;

	str_size = ft_strlen(datas->str);
	datas->p_conv ? ft_putstr_fd("0x", 1) : 0;
	(dot > 0 && !datas->zero_prt && datas->str[0] == '-') ? \
	print_char(1, '-', char_nbr) : 0;
	(datas->d_conv && dot > 0) ? print_char(dot - str_size, '0', char_nbr) : 0;
	i = 0;
	while (datas->str[i] && i < dot)
	{
		if (datas->str[0] == '-' && i == 0)
		{
			i++;
			(datas->zero_prt) ? *char_nbr += 1 : 0;
			if (dot <= 1)
				break ;
		}
		ft_putchar_fd(datas->str[i++], 1);
		*char_nbr += 1;
	}
}
