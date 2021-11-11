NAME			= libftprintf.a

SRCS			=	ft_printf.c	ft_putchar.c	ft_put_c.c	ft_put_d_i.c	ft_put_p.c\
					ft_put_s.c	ft_put_u.c		ft_put_x.c	ft_strlen.c		

HEADER			= libftprintf.h

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I$(HEADER)

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				ar rcs $(NAME) $?

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@		

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all