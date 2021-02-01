/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:33:04 by lwourms           #+#    #+#             */
/*   Updated: 2021/02/01 16:00:07 by lwourms          ###   ########lyon.fr   */
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
	int				is_field;
	int				dot;
	int				is_dot;
	int				star;
	int				minus;
	int				zero;
	int				d_conv;
	int				c_conv;
}				t_datas;

int			ft_printf(const char *input, ...);
void		print_process(t_list *lst, int *charNbr);
void		print_field(int field, t_datas *datas, int *charNbr);
void		print_dot(int dot, t_datas *datas, int *charNbr);
void		print_zeros(int size, t_datas *datas, int *charNbr);

t_list		*treat_input(const char *input, t_list **lst, va_list ap);
t_datas		*get_flags(const char *input, int *i, va_list ap);
t_list		*get_no_conv(char *s, t_list **list);
int			get_conversions(char c, t_datas **datas, t_list **lst, \
			va_list ap);

t_datas		*init_datas(void);
t_list		**fill_list(t_datas *datas, t_list **list, char *str, \
			char *f(const char *));
char		*collect_digits_seq(const char *digits, int start);
int			is_conv(char c);

#endif
