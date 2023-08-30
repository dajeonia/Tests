NAME = a.out
LIBFT = libft
SOURCES = main.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))
LIBS = $(addprefix $(LIB_DIR)/, $(LIBFT).a)

SRC_DIR = .
OBJ_DIR = objs
LIB_DIR = ../libft
INC_DIR = .

LIBFLAGS = -L $(LIB_DIR) -l ft -l readline

CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INC_DIR)

all : $(NAME)

fclean : 
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)

re :
	make fclean
	make all

$(NAME) : $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $@

$(LIBS) :
	make -C $(LIB_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) : 
	mkdir $@

