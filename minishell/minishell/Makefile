FLAGS = -Wall -Wextra -Werror 
NAME = minishell
HEADER = minishell.h
SRC = get_next_line.c ft_fill_mass.c ft_init_mass.c ft_recalloc_dmss.c ft_skok_call_comm.c ft_check_env3.c ft_check_env2.c ft_check_env1.c ft_check_env.c ft_env_utils.c \
	ft_cn_ss_crn_quot.c ft_utils_parse.c ft_call_massivs.c ft_inq_delif.c ft_call_commands.c ft_fill_command.c ft_lets_parse.c ft_utils1.c ft_utils2.c ft_utils3.c \
	ft_utils4.c ft_utils5.c ft_inq_delif1.c ft_fill_command1.c ft_call_commands1.c main.c ft_exit.c ft_exit2.c ft_exec.c ft_echo.c ft_pwd.c ft_env.c ft_unset.c \
	ft_export.c ft_export_utils.c ft_export2.c ft_defaults.c ft_shlvl.c ft_signals.c ft_oldpwd.c ft_not_found.c ft_utils_for_env_func.c ft_defaults2.c ft_defaults3.c \
	ft_check_if_exists.c ft_check_if_exists2.c ft_cd.c ft_cd2.c ft_pipes_redirs.c ft_tokens.c ft_tokens_utils1.c ft_tokens_utils2.c ft_tokens_utils3.c \
	ft_pipes_redirs2.c ft_pipes_redirs3.c ft_pipes_redirs4.c ft_pipes_redirs5.c ft_pipes_redirs6.c ft_pipes_redirs7.c ft_pipes_redirs8.c ft_main_utils.c \
	ft_parser_utils2.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) $(ARGS)

%.o: %.c
	gcc -c $(FLAGS)$< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
