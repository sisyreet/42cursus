NAME			= fdf
SRCS			= sources/draw.c	\
				includes/ft_atoi.c	\
				includes/ft_split.c	\
				sources/get_map.c		\
				includes/get_next_line.c	\
				includes/get_next_line_utils.c	\
				sources/main.c	\
				sources/utils.c	


HEADER			= includes/fdf.h

OBJS 			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g 
DRAW_FLAGS		= -lmlx -framework OpenGL -framework AppKit

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(DRAW_FLAGS) -o $(NAME)

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all