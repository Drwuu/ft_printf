NAME			= libftprintf.a

LIBFT_FOLDER	= libft

SRCS			= ft_printf.c ft_printf_utils.c ft_conv.c

OBJS			= $(SRCS:.c=.o)

LIBFT			= make -C $(LIBFT_FOLDER)

FLAGS			= -Wall -Wextra -Werror

$(NAME):		$(OBJS)
				ar rc $@ $^

%.o:			%.c ft_printf.h
				$(LIBFT)
				gcc $(FLAGS) -c $< -o $@

all:			$(NAME)

clean:
				rm -f $(OBJS)
				make -C $(LIBFT_FOLDER) clean

fclean:			clean
				rm -f $(NAME)
				rm -f ./LIBFT_FOLDER/libft.a 

re:				fclean all

.PHONY:			all clean fclean re
