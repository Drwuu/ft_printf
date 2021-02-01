/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:33:01 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/01 17:16:57 by lwourms          ###   ########lyon.fr   */
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
	if (n > (long long)ft_strlen(base))
		convert_process(n / (long long)ft_strlen(base), result, --len, base);
}

char			*ft_itoa_base(const char *base, unsigned int n)
{
	char		*result;
	int			len;
	int			b_size;
	long long	ll_nb;

	b_size = ft_strlen(base);
	len = findbaselen((long long)n, b_size);
	if (!(result = malloc(sizeof(*result) * (len + 1))))
		return (NULL);
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	ll_nb = n;
	if (n < 0)
	{
		ll_nb = (long long)n * -1;
		result[0] = '-';
	}
	convert_process(ll_nb, result, len, base);
	result[len] = '\0';
	return (result);
}
