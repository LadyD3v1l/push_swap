CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
OBJ_DIR = Obj

SRC = ft_libft.c ft_libft2.c parse_check.c parse_free.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) 
		@echo "CRIOU ISSO $(NAME)"
		@ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
		@echo "Remooooving $(OBJ)"
		@rm -rf $(OBJ_DIR)

fclean: clean
		@echo "Tira Tira ISSO $(NAME)"
		@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
