##
## EPITECH PROJECT, 2023
## minishell1
## File description:
## makefile
##

SRC 	=	src/execution/prompt.c \
			src/builtin/builtin_handler.c \
			src/builtin/my_env.c \
			src/builtin/my_setenv.c \
			src/execution/get_path.c \
			src/execution/execute_handler.c \
			src/builtin/my_cd.c \
			src/builtin/linked_list.c \
			src/builtin/my_unsetenv.c \
			src/parser/redirection.c \
			src/parser/find_redirect.c \
			src/parser/pipe.c \
			src/parser/variables.c	\
			src/free_all.c	\
			src/parser/parser.c	\
			src/parser/lexer.c	\
			src/parser/tree_add_node.c	\
			src/execution/loop.c		\
			src/parser/quote.c			\
			src/line_edition/get_input_line.c	\
			src/line_edition/raw_edition.c	\
			src/shell_history/history.c \
			src/shell_history/command.c \
			src/shell_history/flag.c

TEST_SRC	:=	$(SRC)
TEST_SRC	+=	tests/test_myprintf.c
TEST_SRC	+=	tests/test_builtins.c
TEST_SRC	+=	tests/test_lib.c

SRC			+=	src/main.c

CC        =    gcc

OBJ        =    $(SRC:.c=.o)

TEST_OBJ    =    $(TEST_SRC:.c=.o)

NAME        =    42sh

LIB            =    -L lib/my -lmy

C_FLAGS     =    -Wextra -Wall -Werror -W

CPPFLAGS	=	-Iinclude -g3

all:     create $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(C_FLAGS) $(LIB)

clean:
	@rm -f *.c~
	@rm -f $(OBJ)
	@rm -f $(TEST_OBJ)
	@rm -f vgcore.*
	@find . -name "*.gcno" -type f -delete
	@find . -name "*.gcda" -type f -delete
	@rm -f unit_tests
	@rm -f tests/*.o
	@make -C lib/my clean

fclean:	clean
	@rm -f $(NAME)
	@find . -name "*~" -delete
	@make -C lib/my fclean

debug:	create
	$(CC) $(SRC) -g -o $(NAME) $(C_FLAGS) $(LIB)

unit_tests:	create clean
	$(CC) $(TEST_SRC) $(LIB) -o unit_tests --coverage -lcriterion -Iinclude

tests_run: unit_tests
	@./unit_tests
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branches

create:
	@make -C lib/my

re:	fclean all

.PHONY =	all clean fclean re lib debug unit-tests tests_run create create
