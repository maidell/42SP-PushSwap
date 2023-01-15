NAME		= push_swap

SRCS		= utils.c

MAIN_M		= push_swap.c
SRC_DIR		= ./sources

OBJS		= $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o) $(MAIN_M:.c=.o)) 

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

.PHONY:bonus
bonus: $(BONUS)

$(NAME): $(OBJS)
	@printf "compiling $(NAME) ... \t\t"
	@$(LINKER) $(CFLAGS) $^ $(LIBFT_L) -o $@
	@echo OK!

$(BONUS): $(OBJS_B)
	@printf "compiling $(BONUS) ... \t\t\t"
	@$(LINKER) $(CFLAGS) $^ $(LIBFT_L) -o $@
	@echo OK!

$(LIBFT_A):
	@printf "compiling libft ... \t\t\t"
	@make -s -C $(LIBFT_D)
	@echo OK!

%.o: %.c $(LIBFT_A) $(GNL_A)
	@$(COMPILER) $(CFLAGS) $(LIBFT_I) $< -o $@

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
