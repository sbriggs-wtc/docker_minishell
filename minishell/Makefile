NAME = minishell
SOURCES = ./sources/main.c
COMPILER = gcc
FLAGS = -Wall -Werror -Wextra
LIB = ./libft/libft.a
OBJECTS = main.o
all: $(NAME)
$(NAME):
	@make -C libft/ libft.a
	$(COMPILER) $(FLAGS) -c $(SOURCES) -g
	$(COMPILER) $(FLAGS) $(OBJECTS) $(LIB) -o $(NAME)

libft:
	make -C libft/ libft.a
clean:
	make -C libft/ clean
	rm -fr $(OBJECTS)
fclean: clean
	make -C libft/ fclean
	rm -fr $(NAME)
re: fclean all
