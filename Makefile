NAME		= push_swap

# Path for .c , .h and .o Files 
MAIN_M		= push_swap.c
SRC_DIR		= ./sources
OBJ_DIR =	./objects
OBJ_ALG	= 	./alg_sort
OBJ_SRC =	./src_push_swap
HEADER =    -I ./includes
SRCS		= 	src_push_swap/stack.c \
				src_push_swap/movements.c \
				src_push_swap/push.c \
				src_push_swap/rotate.c \
				src_push_swap/swap.c \
				bubble_sort.c \
				handle_errors.c \
				alg_sort/sort_five.c \
				alg_sort/checkers.c \
				alg_sort/sort_utils.c \

VPATH = sources/alg_sort sources/src_push_swap

#OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o) $(MAIN_M:.c=.o)) 
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o) $(MAIN_M:.c=.o)) 


REQUIRED_DIRS	= ${sort ${dir ${OBJ}}} bin/

LIBFT_D		= ./libft
LIBFT_I		= -I$(LIBFT_D)
LIBFT_L		= -L$(LIBFT_D) -lft
LIBFT_A		= $(LIBFT_D)/libft.a

LINKER		= cc
COMPILER	= cc -c
CFLAGS		= -g -Wall -Werror -Wextra

CLEANUP		= rm -rf

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@printf "compiling $(NAME) ... \t\t"
	@$(LINKER) $(CFLAGS) $^ $(LIBFT_A) -o $@ $(LIBFT_L)
	@echo OK!

$(LIBFT_A):
	@printf "compiling libft ... \t\t\t"
	@make -s -C $(LIBFT_D)
	@echo OK!

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c  
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_ALG)
	@mkdir -p $(OBJ_SRC)
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
