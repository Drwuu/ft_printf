/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:31:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/23 14:30:04 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_char(const char *input, int i, char c)
{
	if (input[i] == c)
		return (0);
	return (-1);
}

static int	is_flag_zero(const char *input, int i)
{
	if (input[i] && input[i] == '0')
		if (input[i + 1] && ft_isdigit(input[i + 1]))
			return (0);
	return (-1);
}

static int	get_field(const char *input, int *i, t_datas **flags)
{
	char	*digits;

	if (ft_isdigit(input[*i]))
	{
		if (!(digits = collect_digits_seq(input, *i)))
			return (-1);
		((t_datas *)*flags)->field = ft_atoi(digits);
		free(digits);
		while (ft_isdigit(input[*i]))
			*i += 1;
		return (1);
	}
	return (0);
}

static int	get_precision(const char *input, int *i, t_datas **flags)
{
	char	*digits;

	if (input[*i] == '.')
	{
		*i += 1;
		if (!(digits = collect_digits_seq(input, *i)))
			return (-1);
		((t_datas *)*flags)->dot = ft_atoi(digits);
		free(digits);
		while (ft_isdigit(input[*i]))
			*i += 1;
		return (1);
	}
	return (0);
}

t_datas		*get_flags(const char *input, int *i, va_list ap)
{
	t_datas *datas;

	if (!(datas = init_datas()))
		return (NULL);
	while (input[*i] && !is_conv(input[*i]))
	{
		*i += 1;
		if (datas->zero == -1)
			datas->zero = is_flag_zero(input, *i);
		if ((get_field(input, i, &datas)) < 0)
			return (NULL);
		if ((get_precision(input, i, &datas)) < 0)
			return (NULL);
		if (datas->star == -1)
			datas->star = get_char(input, *i, '*');
		if (datas->minus == -1)
			datas->minus = get_char(input, *i, '-');
	}
	datas->star == 0 ? (datas->star = va_arg(ap, int)) : \
	(datas->star = -1);
	return (datas);
}
