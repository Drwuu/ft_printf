/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:33:04 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/13 18:21:17 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

#include	<stdarg.h>
#include	"libft/libft.h"

typedef	struct	s_datas
{
	char			*str;
	int				id;
	int				star;
	int				dot;
	int				minus;
	int				zero;
}				t_datas;

int		ft_printf(const char *input, ...);
t_list	**fill_list(t_list **list, char *str, char *f(const char *));
t_list	*ft_no_conv(char *s, t_list **list);
t_list	*ft_conv_char(char c, char *s, t_list **list);
t_list	*ft_conv_str(t_list **list, va_list ap);
t_list	**ft_conv_digits(char c, t_list **list, va_list ap);

#endif
