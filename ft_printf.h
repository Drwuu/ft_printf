/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:33:04 by lwourms           #+#    #+#             */
/*   Updated: 2021/01/23 15:16:37 by lwourms          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> //to remove

typedef	struct	s_datas
{
	char			*str;
	int				field;
	int				star;
	int				dot;
	int				minus;
	int				zero;
}				t_datas;

int				ft_printf(const char *input, ...);
t_list			*treat_input(const char *input, t_list **lst, va_list ap);
t_datas			*get_flags(const char *input, int *i, va_list ap);
t_list			*no_conv(char *s, t_list **list);
int				convert_process(char c, t_datas **datas, t_list **lst, \
				va_list ap);
int				is_conv(char c);
void			treat_field(t_list *lst);

t_datas			*init_datas(void);
t_list			**fill_list(t_datas *datas, t_list **list, char *str, \
				char *f(const char *));
char			*collect_digits_seq(const char *digits, int start);

#endif
