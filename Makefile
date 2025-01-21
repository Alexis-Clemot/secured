##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile
##

SRC = src/ht_dump.c \
	src/new_hashtable.c \
	src/hash.c \
	src/delete_hashtable.c \
	src/ht_insert.c \
	src/ht_delete.c \
	src/ht_search.c \
	src/subfunc/print_nbr.c \
	src/subfunc/sup_data.c \


OBJ = $(SRC:.c=.o)

CFLAGS = -I./include -Wall -Wextra

NAME = libhashtable.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all
