/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:31:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/03 12:31:15 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_char(const char *input, int i, char c)
{
	if (input[i] == c)
		return (1);
	return (0);
}

static int	is_flag_zero(const char *input, int i)
{
	if (input[i] && input[i] == '0')
		if (input[i + 1] && (ft_isdigit(input[i + 1]) || input[i + 1] == '*'))
			return (1);
	return (0);
}

static int	get_field(const char *input, int *i, t_datas **flags, va_list ap)
{
	char	*digits;

	if (ft_isdigit(input[*i]) || input[*i] == '*')
	{
		((t_datas *)*flags)->is_field = 1;
		if (input[*i] == '*' && input[*i - 1] != '.')
		{
			((t_datas *)*flags)->field = va_arg(ap, int);
			*i += 1;
			return (1);
		}
		if (!(digits = collect_digits_seq(input, *i)))
			return (-1);
		((t_datas *)*flags)->field = ft_atoi(digits);
		free(digits);
		while (ft_isdigit(input[*i]))
			*i += 1;
		*i -= 1;
		return (1);
	}
	return (0);
}

static int	get_precision(const char *input, int *i, t_datas **flags, \
va_list ap)
{
	char	*digits;

	if (input[*i] == '.')
	{
		*i += 1;
		((t_datas *)*flags)->is_dot = 1;
		if (input[*i] == '*')
		{
			((t_datas *)*flags)->dot = va_arg(ap, int);
			*i += 1;
			return (1);
		}
		if (!(digits = collect_digits_seq(input, *i)))
			return (-1);
		((t_datas *)*flags)->dot = ft_atoi(digits);
		free(digits);
		while (ft_isdigit(input[*i]))
			*i += 1;
		*i -= 1;
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
		if (input[*i] == '%')
			break;
		if (!datas->zero)
			datas->zero = is_flag_zero(input, *i);
		if (get_field(input, i, &datas, ap) < 0)
			return (NULL);
		if (get_precision(input, i, &datas, ap) < 0)
			return (NULL);
		if (!datas->star)
			datas->star = get_char(input, *i, '*');
		if (!datas->minus)
			datas->minus = get_char(input, *i, '-');
	}
	if (datas->minus)
		datas->zero = 0;
	return (datas);
}
