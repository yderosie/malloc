ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINKNAME = libft_malloc.so 

CC=gcc

LIBFT_PATH ?= libft/

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	src/ft_malloc.c 	\
		src/ft_realloc.c 	\
		src/ft_free.c

INC_FILES = include/ft_malloc.h

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

C_INCLUDE_PATH += $(LIBFT_PATH)/ include/

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

LDFLAGS += -L$(LIBFT_PATH) -lft

all: $(NAME)

MKDIR ?= mkdir

obj/%.o: src/%.c $(INC_FILES)
	$(MKDIR) -p $(dir $@)
	$(CC) -fPIC -c $(CFLAGS) $< -o $@

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJS)
	$(CC) -fPIC $(CFLAGS) -shared -o $(NAME) $(OBJS) $(LDFLAGS)
	ln -s $(NAME) $(LINKNAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) $(LINKNAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_PATH)/libft.a