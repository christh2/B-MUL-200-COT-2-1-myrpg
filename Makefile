##
## EPITECH PROJECT, 2022
## makefile
## File description:
## add some file
##

SRC	=	my_window.c	\
		game.c	\
		destroy.c \
		destroy1.c	\
		set.c	\
		music.c	\
		set1.c	\
		music1.c	\
		usage.c	\
		my_putstr.c	\
		texture_sprite.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter


all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-audio -lcsfml-system -g3
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
