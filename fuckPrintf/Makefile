NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c ft_printf_flags.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ)
	ar rcs $(NAME) $(LIBFT_DIR)/*.o

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all