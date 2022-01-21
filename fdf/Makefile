NAME			= fdf
SRCS			= sources/draw.c	\
				sources/ft_atoi.c	\
				sources/ft_split.c	\
				sources/get_map.c		\
				sources/get_next_line.c	\
				sources/get_next_line_utils.c	\
				sources/main.c	\
				sources/utils.c	


HEADER			= includes/fdf.h

OBJS 			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I$(HEADER)
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