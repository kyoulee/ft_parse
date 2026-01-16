NAME        = ft_parse
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INC_DIRS    = -I include -I src -I src/help

SRC_DIR     = src
HELP_DIR    = src/help
OBJ_DIR     = obj

SRCS        = $(SRC_DIR)/main.c $(HELP_DIR)/parse_help.c
OBJS        = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(OBJ_DIR)/%.o: $(HELP_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re