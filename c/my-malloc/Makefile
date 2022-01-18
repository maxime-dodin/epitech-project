##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## for compile
##

SRC		=		malloc.c	\
				free.c		\
				realloc.c	\
				utils.c		\

OBJ		=		$(SRC:.c=.o)

NAME		=		libmy_malloc.so

CC		=		gcc

RM		=		rm -rf
CPPFLAGS	=		-Wextra -Wall -Werror -fpic -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) *~ $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
