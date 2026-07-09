################################################################################
# STEP: Core Build Automation
#
# This Makefile manages:
#  - Production Binary : $(NAME)
#  - Debug Binary      : $(DEBUG_NAME)
#  - Unit Test Suite   : $(TEST_NAME)
################################################################################

NAME        = ft_parse
TEST_NAME   = ft_parse_t
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

SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/ft_parse.c \
              $(HELP_DIR)/parse_help.c \
              $(INPUT_DIR)/parse_input.c \
              $(LIB_DIR)/parse_color.c \
              $(OPTIONS_DIR)/parse_options_handler.c

TEST_SRCS   = $(SRC_DIR)/main.t.c \
              $(HELP_DIR)/parse_help.t.c \
              $(INPUT_DIR)/parse_input.t.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
TEST_OBJS   = $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRCS:.c=.o)))

OBJS_NO_MAIN = $(filter-out $(OBJ_DIR)/main.o, $(OBJS))

################################################################################
# STEP: Compilation Rules (Object Generation)
#
# This section ensures the object directory exists before compiling source files.
################################################################################

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

################################################################################
# STEP: Standard Production Build
#
# This section handles:
#  - Compiling the primary production binary.
#  - Ensuring all default object dependencies are met.
################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $^ -o $@
	@echo "[SUCCESS] Production build standard sequence complete: $@"

################################################################################
# STEP: Automated Unit Testing Suite
#
# This section handles:
#  - Injecting test-specific compilation flags (TEST_MODE).
#  - Compiling production objects alongside unit test implementations.
#  - Automatically executing the test runner upon successful build.
################################################################################

test: CFLAGS += -D TEST_MODE
test: clean $(TEST_NAME)

$(TEST_NAME): $(OBJS_NO_MAIN) $(TEST_OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $^ -o $@ 
	@echo "[INFO] Test binary compiled successfully. Launching test suite..."
	@./$(TEST_NAME)

################################################################################
# STEP: Debugging and Diagnostic Build
#
# This section handles:
#  - Injecting compiler debugging symbols (-g).
#  - Producing a separate dedicated diagnostic binary.
################################################################################

debug: CFLAGS += -g
debug: clean $(DEBUG_NAME)

$(DEBUG_NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC_DIRS) $^ -o $@
	@echo "[SUCCESS] Debug build configuration established: $@"

################################################################################
# STEP: Cleanup Operations
#
# This section handles:
#  - Removing intermediate workspace artifacts (.o files).
#  - Purging all generated target binaries to ensure a pristine state.
################################################################################

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "[CLEAN] Removed intermediate object files directory."

fclean: clean
	@$(RM) $(NAME) $(TEST_NAME) $(DEBUG_NAME)
	@echo "[FCLEAN] Purged all generated execution binaries."

re: fclean all

.PHONY: all test debug clean fclean re
