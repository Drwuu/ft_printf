/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:33:04 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/16 16:49:03 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

#include	<stdarg.h>
#include	"libft/libft.h"
#include <stdio.h> //to remove

typedef	struct	s_datas
{
	char			*str;
	int				field;
	int				star;
	int				dot;
	int				minus;
	int				zero;
}				t_datas;

int		ft_printf(const char *input, ...);
void	init_datas(t_datas *datas);
int		free_error(t_list *lst, va_list ap);
t_list	**fill_list(t_list **list, char *str, char *f(const char *));
char	*collect_digits_seq(const char *digits, int *start);
t_list	*no_conv(char *s, t_list **list);
t_list	*conv_char(char c, char *s, t_list **list);
t_list	*conv_str(t_list **list, va_list ap);
t_list	**conv_digits(char c, t_list **list, va_list ap);
int		get_flags(const char *input, int *i, t_datas **flags);
char	*get_field(const char *input, int *i);

#endif
