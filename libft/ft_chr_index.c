/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:22:48 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/10 17:51:39 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chr_index(const char *str, const char c, int i)
{
	if (!str || !c)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
