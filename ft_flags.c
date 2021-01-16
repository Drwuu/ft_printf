/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:31:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/16 17:15:19 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag_zero(const char *input, int *i)
{
	if (input[*i + 1] && input[*i + 1] == '0')
		if (input[*i + 2] && ft_isdigit(input[*i + 2]))
		{
			*i += 1;
			return (0);
		}
	return (-1);
}

int			get_flags(const char *input, int *i, t_datas **flags)
{
	char	*temp;

	if (!(*flags = ft_calloc(sizeof(**flags), 1)))
			return (-1);
	init_datas(*flags);
	while (input[*i + 1])
	{
		((t_datas *)*flags)->zero = is_flag_zero(input, i);
		if (ft_isdigit(input[*i + 1]))
		{
			*i += 1;
			if (!(temp = get_field(input, i)))
				return (-1);
			((t_datas *)*flags)->field = ft_atoi(temp);
			dprintf(1, "field = %d\n", ((t_datas *)*flags)->field );
			free(temp);
		}
		((t_datas *)*flags)->dot = (input[*i + 1] == '.') ? 0 : -1;
		((t_datas *)*flags)->star = (input[*i +1 ] == '*') ? 0 : -1;
		((t_datas *)*flags)->minus = (input[*i + 1] == '-') ? 0 : -1;
		*i += 1;
	}
	if (!*flags)
		free(*flags);
	return (1);
}

char		*get_field(const char *input, int *i)
{
	char	*digits;

	if (!(digits = collect_digits_seq(input, i)))
		return (NULL);
	return (digits);
}
