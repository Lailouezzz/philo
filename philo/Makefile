# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/12/13 20:36:21 by ale-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---
# Tools
# ---

MKDIR := mkdir
RM := rm -f

# ---
# Build variables
# ---

# Compiler

CC := gcc

CWARN := all extra
CWARN := $(CWARN:%=-W%)

CFLAGS := $(CWARN) -pthread -g3

# Preprocessor flag

CPPFLAGS := -I.

# Linker

LD := gcc
LDLIBS := 

# ---
# Lib information
# ---

NAME := philo

SRC_DIR := ./
SRCS := utils.c main.c philo_init.c philo_destroy.c error.c philo_start.c \
	philo_life.c philo_log.c philo_eat.c custom_sleep.c
SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJ_DIR := ./build
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_BONUS := 
SRCS_BONUS := $(SRCS_BONUS:%=$(SRC_DIR)/%)
OBJS_BONUS := $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ---
#  General targets
# ---

# Build everything

all: $(NAME)

bonus: all

# Mostly clean (clean everything without the end result)

clean:
	$(RM) -r $(OBJ_DIR)

# Clean everything

fclean: clean
	$(RM) $(NAME)

# Rebuild

re: fclean all

# Bonus

bonus: all
	
.PHONY: all clean fclean re bonus

# ---
# Build targets
# ---

$(NAME): $(OBJS) $(LIBS)
	$(LD) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
