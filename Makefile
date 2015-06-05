#
# lem-in
#
# Makefile
#

#
# Config
#

# Project name
NAME := lem-in

# Project directories
DIRS := src include

# Obj directory
O_DIR := obj

# Makefiles to call
LIBS := libft

# Number of threads
THREADS := 1

# C compiler
C_CC := clang

# Linking compiler
LD_CC := clang

# Clang flags
C_FLAGS := -Wall -Wextra -Werror -O2 -g

# Linking flags
LD_FLAGS := -L libft -lft

# Clang include flags
C_HEADS := -I include/ -I libft/includes/

#
# Internal
#

O_FILES := obj/src/put_anthill.o \
	obj/src/parser_line.o \
	obj/src/calc_routes.o \
	obj/src/parser_save_room.o \
	obj/src/debug.o \
	obj/src/main.o \
	obj/src/parser_save_connection.o \
	obj/src/parser.o

MSG_0 := printf '\033[0;32m%-32.32s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-32.32s\033[0;0m\n'
MSG_END := printf '\n'

.SILENT:

all: $(LIBS) $(NAME)
.PHONY: all

$(NAME): $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && $(MSG_END) || $(MSG_1) $@

obj/src/put_anthill.o: src/put_anthill.c include/lemin.h include/anthill_structs.h
	@mkdir -p obj/src 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

obj/src/parser_line.o: src/parser_line.c include/lemin.h include/anthill_structs.h
	@mkdir -p obj/src 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

obj/src/calc_routes.o: src/calc_routes.c include/lemin.h include/anthill_structs.h
	@mkdir -p obj/src 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

obj/src/parser_save_room.o: src/parser_save_room.c include/lemin.h include/anthill_structs.h
	@mkdir -p obj/src 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

obj/src/debug.o: src/debug.c include/lemin.h include/anthill_structs.h
	@mkdir -p obj/src 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

obj/src/main.o: src/main.c include/lemin.h include/anthill_structs.h
	@mkdir -p obj/src 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

obj/src/parser_save_connection.o: src/parser_save_connection.c include/lemin.h include/anthill_structs.h
	@mkdir -p obj/src 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

obj/src/parser.o: src/parser.c include/lemin.h include/anthill_structs.h
	@mkdir -p obj/src 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

$(LIBS):
	@make -C $@
.PHONY: $(LIBS)

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p obj/src $(O_DIR) 2> /dev/null || true
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
