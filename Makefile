# Makefile for the so_long project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iincludes

# Source files
SRC = main.c comestibles.c drawujo.c enemies.c game_utils.c game.c map.c player.c

# Object files
OBJ = $(SRC:.c=.o)
LIBFT = lib/LIBFT/libft.a
LIBMLX = lib/minilibx-linux/libmlx.a
GNL = lib/ft_et_next_line/get_next_line.o

# Executable name
EXE = so_long

# All target
all: $(EXE)

# Executable target
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L (lib) -o $@

# Library target
$(LIBFT): $(GNL)
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBMLX): $(GNL)
	$(CC) $(CFLAGS) -c $< -o $@
$(GNL): $(GNL)
	$(CC) $(CFLAGS) -c $< -o $@
	

# Object file targets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJ) $(EXE)

# Run target
run: all
	./$(EXE) maps/map.ber
