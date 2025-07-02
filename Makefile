CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -Iincludes
EXEC = push_swap
OBJ_DIR = Obj

#cores
BG_PURPLE = \033[45m
WHITE = \033[97m
BLACK = \033[30m
CINZA = \033[47m\033[30m
PURPLE = \033[35m
RESET = \033[0m

SRC = moves/ft_push.c moves/ft_reverse.c moves/ft_rotate.c moves/ft_swap.c \
		srcs/big_cases.c srcs/calculate.c srcs/extras.c srcs/libft.c \
		srcs/libft2.c srcs/main.c srcs/parse_check.c srcs/parse_free.c \
		srcs/small_cases.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(EXEC)

$(EXEC): $(OBJ)
		@echo "$(BG_PURPLE)$(BLACK)[CRIATE] PUSH_SWAP *-* $(EXEC)$(RESET)"
		@$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		@mkdir -p $(dir $@)
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
		@rm -f $(EXEC)

re: fclean all

.PHONY: re fclean clean all
