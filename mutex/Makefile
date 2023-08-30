NAME = test

SOURCES = main.c
DIRS = 
INCLUDES = 

LIBFT =
LIB =

# **************************************************************************** #

LIB_DIR = .
SRC_DIR = .
OBJ_DIR = objs
INC_DIR = .

SRCS := $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
OBJ_DIRS = $(addprefix $(OBJ_DIR)/, $(DIRS))
INCS := $(addprefix $(INC_DIR)/, $(INCLUDES))
LIBFT := $(addprefix $(LIB_DIR)/, $(LIBFT))

# **************************************************************************** #

MAKE = make
CC = gcc
AR = ar
RM = rm

CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -l$(LIB) -L$(LIB_DIR)

ARFLAGS = crus
RMFLAGS = -rf

# Commands ******************************************************************* #

all : 
	$(MAKE) $(NAME) 

clean :
	$(RM) $(RMFLAGS) objs

fclean : 
	$(RM) $(RMFLAGS) objs
	$(RM) $(RMFLAGS) $(NAME) 

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re

# Dependency ***************************************************************** #

$(NAME) : $(OBJS) #$(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(LIBFT) : 
	$(MAKE) -j3 -C $(LIB_DIR) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR) $(OBJ_DIRS)
	$(CC) $(CFLAGS) $< -c -I $(INC_DIR) -o $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIRS):
	mkdir $@
