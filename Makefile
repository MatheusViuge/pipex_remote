# Variáveis
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = pipex
SRCS = pipex.c utils.c pipex_utils.c 
OBJS = $(SRCS:.c=.o)

# Regras
all: $(NAME)

$(LIBFT):
    @make -C $(LIBFT_DIR)

$(PRINTF):
    @make -C $(PRINTF_DIR)

$(GNL):
    @make -C $(GNL_DIR)

$(NAME): $(LIBFT) $(PRINTF) $(GNL) $(OBJS)
    $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF) $(GNL)

.o: .c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    @make clean -C $(LIBFT_DIR)
    @make clean -C $(PRINTF_DIR)
    @make clean -C $(GNL_DIR)
    rm -f $(OBJS)

fclean: clean
    @make fclean -C $(LIBFT_DIR)
    @make fclean -C $(PRINTF_DIR)
    @make fclean -C $(GNL_DIR)
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
