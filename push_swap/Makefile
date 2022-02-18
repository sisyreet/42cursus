NAME			= push_swap
BNAME			= checker

SRCS			= srcs/main.c srcs/parse.c srcs/push.c \
				srcs/rotate.c srcs/long_sorts.c srcs/short_sorts.c \
				srcs/swap.c srcs/utils.c srcs/checks.c \
				includes/ft_atoi.c includes/ft_split.c includes/ft_strlen.c \
				includes/ft_itoa.c

BSRCS			= the_checker/srcs/main_bonus.c the_checker/srcs/parse_bonus.c the_checker/srcs/push_bonus.c \
				the_checker/srcs/rotate_bonus.c the_checker/srcs/checks_bonus.c \
				the_checker/srcs/swap_bonus.c the_checker/srcs/utils_bonus.c the_checker/srcs/the_check.c \
				the_checker/includes/ft_atoi_bonus.c \
				the_checker/includes/ft_itoa_bonus.c the_checker/includes/ft_split_bonus.c \
				the_checker/includes/ft_strncmp.c the_checker/includes/get_next_line/get_next_line.c \
				the_checker/includes/get_next_line/get_next_line_utils.c

HEADER			= includes/push_swap.h
BHEADER			= includes/push_swap_bonus.h

OBJS			= $(SRCS:.c=.o)
BOBJS			= $(BSRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

.PHONY:			all bonus clean fclean re

all:			$(NAME)

bonus:			$(BNAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

$(BNAME):		$(BOBJS)
				$(CC) $(BOBJS) -o $(BNAME)

%.o:			%.c $(HEADER) $(BHEADER)
				$(CC) $(CFLAGS) -c $< -o $@ 

clean:			
				$(RM) $(OBJS) $(BOBJS)

fclean:			clean
				$(RM) $(NAME) $(BNAME)

re:				fclean all