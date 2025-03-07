# Variáveis
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = pipex
SRCS = main.c utils.c #pipex.c pipex_utils.c 
OBJS = $(SRCS:.c=.o)

# Regras
all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "Libft compiled"

$(NAME): $(LIBFT) $(OBJS)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "Pipex compiled"

.o: .c
	@ $(CC) $(CFLAGS) -c $< -o $@
	@echo "Object files compiled"

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	@echo "Object files removed"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "Pipex removed"

re: fclean all

.PHONY: all clean fclean re
