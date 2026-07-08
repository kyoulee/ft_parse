NAME        = ft_parse
TEST_NAME   = test_suite
DEBUG_NAME  = ft_parse_d
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INC_DIRS    = -I include -I src -I src/help -I src/input -I src/lib -I src/options

SRC_DIR     = src
HELP_DIR    = src/help
INPUT_DIR   = src/input
LIB_DIR     = src/lib
OPTIONS_DIR = src/options
OBJ_DIR     = obj

# 기본 소스 (테스트 파일 제외)
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/ft_parse.c \
              $(HELP_DIR)/parse_help.c \
              $(INPUT_DIR)/parse_input.c \
              $(LIB_DIR)/parse_error.c \
              $(OPTIONS_DIR)/parse_options_handle.c

# 테스트 전용 소스
TEST_SRCS   = $(HELP_DIR)/parse_help.t.c \
              $(INPUT_DIR)/parse_input.t.c

# 오브젝트 파일들
OBJS        = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
TEST_OBJS   = $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRCS:.c=.o)))

all: $(NAME)

# 일반 빌드
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $^ -o $@
	@echo "Build $(NAME) complete!"

# 테스트 빌드 타겟
$(TEST_NAME): $(OBJS) $(TEST_OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $^ -o $@ 
	@echo "Test build complete! Running tests..."
	@./$(TEST_NAME)

test: CFLAGS += -D TEST_MODE
test: clean $(TEST_NAME)

# 디버깅 빌드 타겟
$(DEBUG_NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $^ -o $@

debug: CFLAGS += -g
debug: clean $(DEBUG_NAME)

# .o 생성 규칙들
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(OBJ_DIR)/%.o: $(HELP_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(OBJ_DIR)/%.o: $(INPUT_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(OBJ_DIR)/%.o: $(OPTIONS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test debug