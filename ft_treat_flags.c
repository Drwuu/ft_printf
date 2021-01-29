/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:59:57 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/29 14:57:27 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		display_field(t_list *lst, int paddingLeft, int *charNbr)
{
	int		i;
	int		size;
	int		str_size;
	t_datas	*datas;

	datas = lst->content;
	if (datas->dot > -1 && datas->dot <= (int)ft_strlen(datas->str))
		str_size = datas->dot;
	else
		str_size = ft_strlen(datas->str);
	if (datas->is_field)
	{
		if (paddingLeft)
			size = datas->field - str_size;
		else
			size = (datas->field >= 0) ? datas->field - str_size : \
			(datas->field * -1) - str_size;
		i = 0;
		while (i++ < size)
		{
			(datas->zero > -1) ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
			*charNbr += 1;
		}
	}
}

static int	display_dot_process(t_datas *datas, int str_size, char	**str, \
int *charNbr)
{
	int		i;
	int		size;

	if (datas->dot > -1)
	{
		if (datas->dot >= str_size && datas->d_conv)
		{
			size = datas->dot - str_size;
			i = 0;
			while (i++ < size)
			{
				ft_putchar_fd('0', 1);
				*charNbr += 1;
			}
			return (0);
		}
		else if (!datas->d_conv)
		{
			if (!(*str = ft_substr(datas->str, 0, datas->dot)))
				return (-1);
			return (1);
		}
	}
	return (0);
}

int			display_dot(t_list *lst, char **str, int *charNbr)
{
	t_datas	*datas;

	datas = lst->content;
	return (display_dot_process(datas, ft_strlen(datas->str), str, charNbr));
}
