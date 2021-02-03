/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:33:01 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/03 16:40:47 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		findbaselen(long long n, int b_size)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= b_size;
	}
	return (len);
}

static void		convert_process(long long n, char *result, int len, const char *base)
{
	result[len - 1] = base[n % ft_strlen(base)];
	if (n >= (int)ft_strlen(base))
		convert_process(n / ft_strlen(base), result, --len, base);
}

char			*ft_itoa_base(const char *base, long long n)
{
	char		*result;
	int			len;
	int			b_size;

	b_size = ft_strlen(base);
	len = findbaselen(n, b_size);
	if (!(result = malloc(sizeof(*result) * (len + 1))))
		return (NULL);
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	convert_process(n, result, len, base);
	result[len] = '\0';
	return (result);
}
