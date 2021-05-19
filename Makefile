##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## mysh
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I./

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my/
	$(CC) -g -o $(NAME) $(OBJ) lib/my/libmy.a $(CFLAGS)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ)
	$(RM) *~

fclean:	clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME)

re:	fclean all

.Phony:	all clean fclean re
