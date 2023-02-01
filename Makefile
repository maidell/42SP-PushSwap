NAME		= push_swap

SRCS		= utils.c

# Path for .c , .h and .o Files 
MAIN_M		= push_swap.c
SRC_DIR		= ./sources
OBJ_DIR =	./objects
HEADER =    -I ./includes


OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o) $(MAIN_M:.c=.o)) 

LIBFT_D		= libft
LIBFT_I		= -I$(LIBFT_D)
LIBFT_L		= -L$(LIBFT_D) -lft
LIBFT_A		= $(LIBFT_D)/libft.a

LINKER		= cc
COMPILER	= cc -c
CFLAGS		= -g -Wall -Werror -Wextra

CLEANUP		= rm -rf

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@printf "compiling $(NAME) ... \t\t"
	@$(LINKER) $(CFLAGS) $^ $(LIBFT_L) -o $@
	@echo OK!

$(LIBFT_A):
	@printf "compiling libft ... \t\t\t"
	@make -s -C $(LIBFT_D)
	@echo OK!

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_A) 
	@mkdir -p $(OBJ_DIR)
	@$(COMPILER) $(CFLAGS) $(LIBFT_I) $(HEADER) $< -o $@

.PHONY: clean
clean:
	@printf "cleaning $(NAME) objects ... \t\t"
	@$(CLEANUP) $(OBJS)
	@echo OK!
	@printf "cleaning $(BONUS) objects ... \t\t"
	@$(CLEANUP) $(OBJS_B)
	@echo OK!
	@printf "cleaning libft objects ... \t\t"
	@make -s -C $(LIBFT_D) clean
	@echo OK!
	
.PHONY: fclean
fclean: clean
	@printf "cleaning $(NAME) executable ... \t"
	@$(CLEANUP) $(NAME)
	@echo OK!
	@printf "cleaning libft static library ... \t"
	@make -s -C $(LIBFT_D) fclean
	@echo OK!

.PHONY: re
re: fclean all
