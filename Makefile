##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC = $(shell find Files/*.c)

NAME = my_defender

all: $(NAME)

$(NAME):
			gcc $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-system \
			-lcsfml-window -lcsfml-audio -lm

clean:
			rm $(NAME)

fclean:
			rm $(NAME)

re:
			make clean
			make all
