NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = minishell.c utils_00.c includes/ft_split_op.c

OBJCS = $(FILES:.c=.o)

INCLUDES = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJCS)
	@make -C libft
	@$(CC)  $(OBJCS) $(CFLAGS) $(INCLUDES) -o $(NAME)

%.o:%.c
	@$(CC)  $(CFLAGS)  -c $<  -o $@

clean :
	@rm -fr libft/*.o && rm -fr libft/*.a
	@rm -fr $(OBJCS)
	@echo "\033[0;31m𝑶𝒃𝒋𝒆𝒄𝒕𝒔' 𝒄𝒍𝒆𝒂𝒏𝒆𝒅\033[0m"

fclean : clean
	@rm -fr $(NAME)
	@echo "\033[1;33m𝙀𝙫𝙚𝙧𝙮𝙩𝙝𝙞𝙣𝙜'𝙨 𝙘𝙡𝙚𝙖𝙣𝙚𝙙\033[0m"

re :fclean all

push :
	git add .
	git commit -m "Updated"
	git push