##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Lib builder makefile
##

SRC =	my_printf.c	\
		my_compute_power_rec.c	\
		my_getnbr.c	\
		my_putnbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_stderr.c	\
		my_nbrlen.c	\
		my_revstr.c	\
		my_strncpy.c \
		my_strcmp.c \
		printf_lib/my_put_udecimal.c	\
		printf_lib/my_putfloat.c	\
		printf_lib/my_puthex_capital.c	\
		printf_lib/my_puthex.c	\
		printf_lib/my_putoctal.c	\
		printf_lib/my_putptr.c	\
		printf_lib/functions_ptr/simple_flags.c \
		printf_lib/functions_ptr/rest_flags.c \
		printf_lib/functions_ptr/rest_flags_2.c \
		split.c \
		my_strcat.c \
		my_strncmp.c \
		my_arrlen.c \
		my_strcpy.c \
		my_strdup.c \
		my_show_word_array.c \
		my_isalpha.c \
		my_isalphanum.c \
		remove_first_char.c \
		my_copitab.c		\
		my_str_to_word_array.c	\
		my_str_isnum.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../
		@cp my.h ../../include/
		@echo [OK] "Library successfully compiled"

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
