NAME			= fdf

SRCS			= includes/ft_atoi.c	\
				includes/ft_split.c	\
				includes/get_next_line.c	\
				includes/get_next_line_utils.c	\
				sources/draw.c	\
				sources/get_map.c		\
				sources/main.c	\
				sources/utils.c	

SRCS_BONUS		= includes/ft_atoi.c	\
				includes/ft_split.c	\
				includes/ft_memset.c \
				includes/get_next_line.c	\
				includes/get_next_line_utils.c	\
				sources/draw_bonus.c	\
				sources/get_map_bonus.c		\
				sources/main_bonus.c	\
				sources/init_bonus.c	\
				sources/key_hook_bonus.c	\
				sources/utils_bonus.c	


HEADER			= includes/fdf.h
HEADER_BONUS	= includes/fdf_bonus.h

OBJS 			= $(SRCS:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g 
MLX_FLAGS		= -lmlx -framework OpenGL -framework AppKit

.PHONY:			all bonus clean fclean re

all:			$(NAME)

$(NAME):		$(if $(findstring bonus, $(MAKECMDGOALS)), $(OBJS_BONUS), $(OBJS))
				$(CC) $^ $(MLX_FLAGS) -o $(NAME)

bonus:			$(NAME)

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean:			
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all