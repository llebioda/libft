CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCSFILES =	ft_atoi.c ft_itoa.c ft_bzero.c ft_calloc.c ft_utils.c \
			char/ft_isalnum.c char/ft_isalpha.c char/ft_isascii.c char/ft_isdigit.c char/ft_isprint.c char/ft_tolower.c char/ft_toupper.c \
			mem/ft_memchr.c mem/ft_memcmp.c mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			str/ft_split.c str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c \
			str/ft_strlen.c str/ft_strmapi.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c str/ft_strtrim.c str/ft_substr.c \
			list/ft_lstnew.c list/ft_lstadd_front.c list/ft_lstsize.c list/ft_lstlast.c list/ft_lstadd_back.c \
			list/ft_lstdelone.c list/ft_lstclear.c list/ft_lstiter.c list/ft_lstmap.c list/ft_lst_utils.c \
			gnl/get_next_line.c

SRCDIR = ./
SRCS = $(addprefix $(SRCDIR), $(SRCSFILES))
OBJDIR = ./build/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCSFILES:.c=.o)))
DEPS = $(OBJS:.o=.d)

INCLUDES = -I . -I ./gnl/

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MF $(@:.o=.d) -c $< -o $@

$(OBJDIR)%.o: $(SRCDIR)*/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MF $(@:.o=.d) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean
	@$(MAKE) --no-print-directory all

-include $(DEPS)

# show a variable value with : make print-VARIABLE
print-%:
	@echo $* = $($*)

.PHONY: all clean fclean re