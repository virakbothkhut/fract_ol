NAME		:= fractol
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all		: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@echo "${LIGHT_ORANGE} FYI: $(LIGHT_RED)All successfully removed${BLUE} !!!$(LIGHT_BLUE)\n"

fclean: clean
	@rm -r -f $(NAME)
	@echo "$(LIGHT_BROWN) $(BOLD)$(NAME) $(LIGHT_MAGENTA) Clean is finished ✅ ◎ $(BRIGHT_PURPLE) !!!! $(LIGHT_PINK) "

re: clean all

.PHONY: all, clean, fclean, re, libmlx
# Extended Colors
LIGHT_RED =       \033[1;31m
LIGHT_GREEN =     \033[1;32m
LIGHT_YELLOW =    \033[1;33m
LIGHT_BLUE =      \033[1;34m
LIGHT_MAGENTA =   \033[1;35m
LIGHT_CYAN =      \033[1;36m
LIGHT_WHITE =     \033[1;37m

# 256-color palette (examples)
LIGHT_ORANGE =    \033[38;5;214m
LIGHT_BROWN =     \033[38;5;130m
LIGHT_GRAY =      \033[38;5;250m
BRIGHT_PURPLE =   \033[38;5;175m
BRIGHT_PINK =     \033[38;5;213m
DARK_BLUE =       \033[38;5;33m
LIGHT_PURPLE =    \033[38;5;183m
VIOLET =          \033[38;5;201m

# RGB colors
LIGHT_GREEN_RGB = \033[38;2;144;238;144m
TURQUOISE =       \033[38;2;64;224;208m
LAVENDER =        \033[38;2;230;230;250m
SKY_BLUE =        \033[38;2;135;206;235m
LIGHT_PINK =      \033[38;2;255;182;193m

# Background colors
BG_LIGHT_RED =    \033[48;5;160m
BG_LIGHT_GREEN =  \033[48;5;118m
BG_LIGHT_BLUE =   \033[48;5;117m
BG_LIGHT_YELLOW = \033[48;5;226m
BG_BLACK =        \033[48;5;16m
BG_WHITE =        \033[48;5;15m
