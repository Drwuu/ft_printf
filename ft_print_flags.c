/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:59:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/12 18:16:00 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_char(int size, char c, int *charNbr)
{
	int	i;
	
	i = 0;
	while (i++ < size)
	{
		ft_putchar_fd(c, 1);
		*charNbr += 1;
	}
}

void		print_zeros(int size, t_datas *datas, int *charNbr)
{
	if (datas->str[0] == '-')
	{
		print_char(1, '-', charNbr);
		*charNbr -= 1;
	}
	print_char(size, '0', charNbr);
}

void		print_field(int size, t_datas *datas, int *charNbr)
{
	if (!datas->zero || (datas->zero && datas->is_dot))
		print_char(size, ' ', charNbr);
}

void		print_dot(int dot, t_datas *datas, int *charNbr)
{
	int i;
	int	str_size;

	str_size = ft_strlen(datas->str);
	datas->p_conv ? ft_putstr_fd("0x", 1) : 0; 
	(datas->str[0] == '-') ? print_char(1, '-', charNbr) : 0;
	(datas->d_conv && dot > 0) ? print_char(dot - str_size, '0', charNbr) : 0;
	i = 0;
	while (datas->str[i] && i < dot)
	{
		if (datas->str[0] == '-' && i == 0)
			i++;
		ft_putchar_fd(datas->str[i++], 1);
		*charNbr += 1;
	}
}
