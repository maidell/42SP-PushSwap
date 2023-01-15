NAME =      push_swap.a
HEADER =    -I ./includes
SRC_DIR =   ./sources
OBJ_DIR =	./objects
LIBFT 	=	./libraries/libft/libft.a
PRINTF 	=	./libraries/printf/libftprintf.a
SRC_FILES =   push_swap.c utils.c

CC =		cc 

CFLAGS =	-Wall -Wextra -Werror -g3

SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) #$(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(PRINTF) -o $(NAME) 

$(LIBFT) $(PRINTF):
	make -C ./libraries/libft
	make -C ./libraries/printf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c  $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libraries/libft
	make clean -C ./libraries/printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libraries/libft
	make fclean -C ./libraries/printf

re: fclean all

.PHONY: all clean fclean re
