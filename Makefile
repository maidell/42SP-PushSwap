NAME =      push_swap
HEADER =    -I ./includes
SRC_DIR =   ./sources
OBJ_DIR =	./objects
LIBFT 	=	./libft/libft.a
SRC_FILES =   	push_swap.c utils.c 

CC =		cc 

CFLAGS =	-Wall -Wextra -Werror -g3

SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

$(LIBFT):
	make -C ./libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c  $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
