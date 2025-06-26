CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
EXEC = push_swap
OBJ_DIR = Obj

#cores
BG_PURPLE = \033[45m
WHITE = \033[97m
BLACK = \033[30m
CINZA = \033[47m\033[30m
PURPLE = \033[35m
RESET = \033[0m

SRC = ft_libft.c ft_libft2.c parse_check.c parse_free.c ft_push.c ft_reverse.c \
		ft_rotate.c ft_swap.c quick_lower.c quick_sort.c main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME) $(EXEC)

$(NAME): $(OBJ) 
		@echo "$(BG_PURPLE)$(WHITE)[REBUILD] PUSH_SWAP *-*$(RESET)"
		@ar rcs $@ $^

$(EXEC): main.c $(NAME)
		@echo "$(BG_PURPLE)$(BLACK)[REBUILD] Linkando $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) main.c $(NAME) -o $(EXEC)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		@echo "$(PURPLE)[COMPILE] $<$(RESET)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@echo "$(CINZA)$(BLACK)=======$(RESET)"
		@echo "$(CINZA)$(BLACK)| * * |$(RESET)"
		@echo "$(CINZA)$(BLACK)|* *  |$(RESET)"
		@echo "$(CINZA)$(BLACK)| * * |$(RESET)"
		@echo "$(CINZA)$(BLACK)|  * *|$(RESET)"
		@echo "$(CINZA)$(BLACK)|  * *|$(RESET)"
		@echo "$(CINZA)$(BLACK)| * * |$(RESET)"
		@echo "$(CINZA)$(BLACK)|* *  |$(RESET)"
		@echo "Andou, andou e no lixo parouu! 🗑️"
		@rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: re fclean clean all
