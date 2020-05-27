##
## EPITECH PROJECT, 2019
## my_sokoban
## File description:
## Makefile
##

NAME	=	my_sokoban

SRC	=	src/sokoban.c		\
		src/split_map.c		\
		src/count_lines.c	\
		src/control_lr.c	\
		src/control_ud.c	\
		src/error_handling.c	\
		src/help_display.c	\
		src/my_strlen.c		\
		src/my_putchar.c	\
		src/my_putstr.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall -g3

CPPFLAGS=	-I./include/ -lncurses

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
