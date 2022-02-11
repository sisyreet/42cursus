NAME_SR			= server
NAME_CL			= client

SRCS_SR			= server.c \
				server_utils.c \
				client_utils.c

SRCS_CL			= client.c \
				server_utils.c \
				client_utils.c

HEADER			= includes/minitalk.h

OBJS_SR			= $(SRCS_SR:.c=.o)
OBJS_CL			= $(SRCS_CL:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

.PHONY:			all clean fclean re

all:			$(NAME_SR) $(NAME_CL)

$(NAME_SR):		$(OBJS_SR)
				$(CC) $(OBJS_SR) -o $(NAME_SR)

$(NAME_CL):		$(OBJS_CL)
				$(CC) $(OBJS_CL) -o $(NAME_CL)

%.o:			%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@ 

clean:			
				$(RM) $(OBJS_SR) $(OBJS_CL)

fclean:			clean
				$(RM) $(NAME_SR) $(NAME_CL)

re:				fclean all