/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festermo <festermo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:11:27 by wjena             #+#    #+#             */
/*   Updated: 2020/12/28 18:34:13 by festermo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct	s_start
{
	char		*line;
	char		path[PATH_MAX + 1];
	int			gnl_val;
	int			ret;
	int			j;
	int			tmp_fd;
	int			tmp_fd1;
}				t_start;

typedef struct	s_mass
{
	int			i;
	int			j;
	int			k;
	int			l;
	char		**strings;
}				t_mass;

typedef struct	s_pipes
{
	char		**strings;
	int			k;
	int			i;
	int			j;
	char		symb;
	int			flag;
	char		*before;
	int			fds[2];
	int			fd;
	pid_t		pid;
	int			tmp_fd;
	int			tmp_fd1;
	int			is_smth;
	char		*buf;
}				t_pipes;

typedef struct	s_cd
{
	char		act_path[PATH_MAX + 1];
	char		*append_str;
	int			i;
	char		*str_buf;
	int			flag;
	char		*str_buf2;
	char		*act_buf;
	int			flag_olpwd;
}				t_cd;

typedef struct	s_ifex
{
	char		**path;
	char		*buf;
	int			counter;
	int			j;
	int			i;
	char		*buf2;
	char		*path_append;
	int			fd;
}				t_ifex;

typedef struct	s_def
{
	int			i;
	int			j;
	char		**path;
	int			counter;
	char		*buf;
	char		*path_append;
	char		**argv;
	char		*buf2;
	int			fd;
	pid_t		pid;
}				t_def;

typedef struct	s_func
{
	int			shlvl;
	int			is_there_sh;
	int			index;
}				t_func;

typedef struct	s_params
{
	int			quotas;
	int			dquotas;
	int			semicolon;
	char		**commands;
	char		**cmdtmp;
	int			commandquan;
	int			flag_create;
	int			flag_create2;
	int			flag_govna;
	int			col_pipe;
	int			col_redir;
	char		*flagsp;
	char		*flagsr;
	char		*starmass;
	int			lol;
	int			index;
	int			index_redir;
	int			index_redir_buf;
	int			flag_for_fill;
	char		**string_to_free;
	int			string_index;
}				t_params;

typedef struct	s_parser
{
	int			ints;
	int			tmp_fd1;
	int			flag2;
	int			pr;
	int			flag1;
	char		*crtline;
	int			quantity;
	int			fl;
	int			lenlen;
	int			lenlen1;
	int			flap_sp;
	int			flap_sp1;
	int			dollar;
	int			flag_pip;
	int			mas_col;
	int			flag_ekr;
	int			flag_ekr1;
	int			flag_red_name;
	int			flag_red_name_col;
	int			flag_red_name1;
	int			flag_red_name_col1;
	int			flag_red_name2;
	int			flag_red_name_col2;
	int			flag_spc;
	char		**mass_for_names;
	int			quanred;
	int			dmss;
	int			index_for_redirects;
	int			if_synt_error;
	int			flagvih;
	t_params	params;
	t_def		def;
	t_ifex		ifex;
	t_cd		cd;
	t_pipes		pipes;
	t_mass		mass;
	t_start		start;
}				t_parser;

typedef struct	s_sig
{
	int			flag;
	pid_t		pid;
}				t_sig;

int				get_next_line(int fd, char **line);
char			*ft_strcpy(char *s1, char *s2);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t num, size_t size);
char			*ft_strdup(char *src);
char			*ft_strchr(const char *str, int ch);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
int				ft_isalnum(int a);
int				ft_isalpha(int a);
void			*ft_memset(void *dst, int c, size_t n);
char			*ft_strdup(char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t k);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_lets_parse(t_parser *parser, char **envp);
void			ft_init_params(t_parser *parser);
void			ft_endparser(t_parser *parser, int i);
void			ft_create_mass(t_parser *parser);
void			ft_free_commands(t_parser *parser);
void			ft_recalloc_commands(t_parser *parser);
int				ft_start_parse(t_parser *parser, char **envp);
void			ft_free_double_mass(char **str);
void			ft_fill_star_mas(t_parser *parser, char c);
void			ft_fill_red_name(t_parser *parser, char c);
void			ft_fill_flags(t_parser *parser, char c);
void			ft_fill_flags_red(t_parser *parser, char c);
void			ft_init_commands(t_parser *parser);
void			ft_init_cmdtmp(t_parser *parser);
void			ft_free_commands(t_parser *parser);
void			ft_free_tmp(t_parser *parser);
void			ft_fill_tmp(t_parser *parser);
void			ft_replace_tmp(t_parser *parser);
void			ft_replace_mass(t_parser *parser);
int				ft_call_commands1(t_parser *parser, int len);
int				ft_check_space(t_parser *parser, int i);
int				ft_skok_tam(char *envp, int len);
void			ft_skok_tam1(char *envp, int len, t_parser *parser, int *m);
void			ft_fill_dollar(t_parser *parser, int *m);
void			ft_check_env3_del(t_parser *parser, int *i, int *j);
void			ft_check_env3_del1(int *k, t_parser *parser, char **search);
void			ft_check_env3(t_parser *parser, int *i, char **envp, int *m);
void			ft_elsefree(int ret_val, char **read_line);
void			ft_check_env_del(t_parser *parser, int *i, int *j);
void			ft_check_env_del1(int *k, t_parser *parser, char **search);
int				ft_check_env(t_parser *parser, int *i, char **envp);
void			ft_check_env1_del(t_parser *parser, int *i, int *j);
void			ft_check_env1_del1(int *k, t_parser *parser, char **search);
void			ft_check_env1(t_parser *parser, int *i, char **envp, int *m);
void			ft_check_env2_del(t_parser *parser, int *i, int *j);
void			ft_check_env2_del1(int *k, t_parser *parser, char **search);
int				ft_check_env2(t_parser *parser, int *i, char **envp);
int				ft_zikl(char **search, char *envp, int *kk);
int				ft_zikl1(char **search, int *kk, char *envp);
void			ft_check_qual1(char **search, t_parser *parser, int *kk);
int				ft_zikl3(t_parser *parser, char **search, char *envp, int *m);
void			ft_check_qual4(t_parser *parser, char **search, int *m);
int				ft_check_next(t_parser *parser, int i);
void			ft_skip_space(t_parser *parser, int *i);
void			ft_calloc_red_name(t_parser *parser);
void			ft_in_quot(t_parser *parser, int *i, int *j, char **envp);
void			ft_in_quot1(t_parser *parser, int *i, int *j);
void			ft_quanred_quot(t_parser *parser);
void			ft_free_double_mass(char **str);
int				ft_check_home(char **envp);
void			ft_callred_quot(t_parser *parser);
void			ft_fill_home(t_parser *parser, char **envp, int *m);
void			ft_callred_quot(t_parser *parser);
void			ft_call_starmass(t_parser *parser);
void			ft_call_flags_red(t_parser *parser);
void			ft_call_flags(t_parser *parser);
int				ft_del_if(t_parser *parser, int *i, int *j, char **envp);
void			ft_in_quot11(t_parser *parser, int *i, int *j, char **envp);
void			ft_in_quot12(t_parser *parser, int *i, int *j, int len);
int				ft_del_if1(t_parser *parser, int *i, int *j, char **envp);
int				ft_call_commands(t_parser *parser, int i, char **envp);
void			ft_fill_command(t_parser *parser, int len, int *i, char **envp);
void			ft_in_quot11_pr(t_parser *parser, int *i);
void			ft_del_if_doll(t_parser *parser, int sum, int *j);
int				ft_del_if_ekr(t_parser *parser, int *i);
void			ft_fill_command4(t_parser *parser, int *i, int len, int *j);
int				ft_fill_command3(t_parser *parser, int *i, int len, int *j);
void			ft_fill_command2(t_parser *parser, int *i);
void			ft_call_commands_init(t_parser *parser);
int				ft_call_commands2(t_parser *parser, int *i, int *j,
				char **envp);
void			ft_call_commands3(t_parser *parser, int flaggg);
int				ft_call_commands4(t_parser *parser, int flaggg, int *i, int *j);
void			ft_call_commands5(t_parser *parser, int *i);
int				ft_exit(char *str, t_parser *parser);
void			ft_exit1(t_parser *parser);
void			ft_exit2(t_parser *parser, char ***strings);
void			ft_exit3(t_parser *parser, char ***strings);
void			ft_exit4(t_parser *parser);
void			ft_exit5(t_parser *parser, char ***strings);
int				ft_isnum(char c);
int				ft_if_number(char *str);
void			ft_exit6(t_parser *parser, char ***strings);
int				ft_exec(char **envp, char *str, t_parser *parser);
void			ft_exec1(t_parser *parser, char *prog_name);
void			ft_exec2(t_parser *parser, char **envp,
				char **prog_name, char **path_append);
char			*ft_exec3(char **str, int *len, char **prog_name);
void			ft_get_val(t_parser *parser);
int				ft_echo_skip_flags(char **str, int len, int *flag_echo);
int				ft_echo(char *str, t_parser *parser);
int				ft_find_flag(char *str, int i);
int				ft_pwd(char *str, t_parser *parser);
int				ft_env(char **envp, char *str, t_parser *parser);
int				ft_find_eq(char *str);
int				ft_find_in_env(char **envp, char *str);
int				ft_check_symb_before_eq(char *str);
int				ft_unset(char ***envp, char *str, t_parser *parser);
void			ft_unset2(char **strings, char ***envp, int *j);
void			ft_unset3(t_parser *parser, char **strings, int *j);
int				ft_export(char ***envp, char *str, t_parser *parser);
void			ft_printing_w_quotes(char *str);
void			ft_export_check(char *name, char ***envp, int i);
int				ft_export_srch(char *name, char **envp);
int				ft_export_without_anyth(char *str, char ***envp);
int				ft_export1(char **str, char **envp);
void			ft_export2(char **strings, t_parser *parser, char ***envp);
void			ft_export3(char **strings, int j, t_parser *parser);
int				ft_export4(char **strings, t_parser *parser,
				char ***envp, int **ints);
void			ft_export_init_ints(int **ints);
void			ft_export_do_zero(int **ints);
int				ft_defaults(char *str, char **envp, int flag, t_parser *parser);
int				ft_find_path(char **envp);
void			ft_if_shlvl(char **envp, t_func *func);
void			ft_change_shlvl(char ***envp, t_func *func, t_parser *parser);
void			ft_make_shlvl(char ***envp, t_parser *parser);
void			ft_sigint();
void			ft_sigquit();
void			ft_put_oldpwd_to_end(char ***envp, char *act_path,
				t_parser *parser);
char			*ft_find_pwd(char **envp);
void			ft_if_there_is_pwd(char ***envp, t_parser *parser,
				char **oldpwd);
void			ft_make_oldpwd_nothing(char **envp);
void			ft_change_oldpwd(char ***envp, int i, t_parser *parser);
int				ft_find_oldpwd(char **envp, int flag);
int				ft_isnum(char c);
int				ft_if_number(char *str);
char			*ft_find_pwd(char **envp);
void			ft_change_pwd(char ***envp, char *act_path, t_parser *parser);
void			ft_pwd_eq_envp(t_parser *parser, char ***envp, int i);
int				ft_not_found(char *str, t_parser *parser, int fd);
int				ft_find_in_env(char **envp, char *str);
int				ft_check_symb_before_eq(char *str);
int				ft_find_path(char **envp);
void			ft_make_free_str(t_parser *parser);
void			ft_get_val(t_parser *parser);
void			ft_defaults1(t_parser *parser, char **envp);
void			ft_defaults2(t_parser *parser);
void			ft_defaults3(t_parser *parser, char *str);
void			ft_defaults4(t_parser *parser, char **envp);
void			ft_defaults5(t_parser *parser, char **envp);
void			ft_defaults6(t_parser *parser);
void			ft_defaults7(t_parser *parser);
void			ft_defaults8(t_parser *parser);
void			ft_defaults9(t_parser *parser, char *str);
void			ft_defaults10(t_parser *parser);
void			ft_defaults11(t_parser *parser, char *str, char **envp);
void			ft_defaults12(t_parser *parser);
void			ft_defaults13(t_parser *parser, char **envp, int flag);
int				ft_check_if_exists(t_parser *parser, char **envp);
int				ft_check_if_our_func(char *str, char *to_find);
int				ft_check_if_exists1(t_parser *parser);
void			ft_check_if_exists2(t_parser *parser, char **envp);
void			ft_check_if_exists3(t_parser *parser);
void			ft_check_if_exists4(t_parser *parser);
void			ft_check_if_exists5(t_parser *parser);
void			ft_check_if_exists6(t_parser *parser);
int				ft_check_if_our_func(char *str, char *to_find);
int				ft_cd(char *str, char ***envp, t_parser *parser);
int				ft_check_if_builtin(char **str, char ***envp,
				t_parser *parser, int tmp_fd1);
void			ft_cd_init(t_parser *parser);
void			ft_cd_end(t_parser *parser, char ***envp);
void			ft_cd2_part_2(t_parser *parser);
int				ft_cd2(t_parser *parser, char ***envp);
void			ft_cd3(t_parser *parser, char ***envp);
void			ft_cd4(t_parser *parser);
void			ft_cd5(t_parser *parser, char *str);
void			ft_cd5_1(t_parser *parser);
void			ft_cd5_2(t_parser *parser, char *str);
int				ft_exec_pipes_redirs(char *str, char ***envp, t_parser *parser);
int				ft_smth(char *str);
char			**ft_pipes_and_redirs(char *str, t_parser *parser);
int				ft_pipes(t_parser *parser, char ***envp);
int				ft_redirs_in_pipes(t_parser *parser);
void			ft_redirs_in_pipes2(t_parser *parser);
void			ft_redirs_in_pipes3(t_parser *parser);
void			ft_redirs_in_pipes4(t_parser *parser);
void			ft_redirs_in_pipes5(t_parser *parser);
int				ft_redirs_in_pipes6(t_parser *parser);
int				ft_redirs_in_pipes7(t_parser *parser);
int				ft_redirs_in_pipes8(t_parser *parser);
void			ft_redirs_print_error(t_parser *parser);
void			ft_check_token3(t_parser *parser, int k);
void			ft_check_token2(t_parser *parser, int k);
void			ft_check_token1(t_parser *parser, int k);
void			ft_check_token(t_parser *parser);
int				ft_check_token3_dop(t_parser *parser);
int				ft_check_token3_dop1(int i, int k, t_parser *parser, int flag);
int				ft_check_token3_dop2(int *k, t_parser *parser, int flag);
void			ft_check_token3_dop3(t_parser *parser, int *i, int *flag);
void			ft_check_token3(t_parser *parser, int k);
int				ft_check_token2_dop(t_parser *parser);
void			ft_check_token2(t_parser *parser, int k);
void			ft_check_token1_dop(t_parser *parser);
void			ft_check_token1(t_parser *parser, int k);
int				ft_check_token_dop1_2(t_parser *parser, int *i);
int				ft_check_token_dop1_3(t_parser *parser, int *i);
int				ft_check_token_dop1(t_parser *parser, int *i);
int				ft_check_token_dop2_1(t_parser *parser, int *i);
int				ft_check_token_dop2_2(t_parser *parser, int *i);
int				ft_check_token_dop2(t_parser *parser, int *i);
void			ft_redirs_in_pipes_funcs_call(t_parser *parser);
int				ft_pipes2(t_parser *parser, char ***envp);
void			ft_pipes3(t_parser *parser, char ***envp);
void			ft_pipes4(t_parser *parser);
void			ft_pipes5(t_parser *parser);
void			ft_pipes6(t_parser *parser);
void			ft_pipes7(t_parser *parser);
int				ft_redirs(t_parser *parser);
void			ft_redirs2(t_parser *parser);
void			ft_redirs3(t_parser *parser);
void			ft_redirs4(t_parser *parser);
void			ft_redirs5(t_parser *parser);
int				ft_redirs6(t_parser *parser);
int				ft_redirs7(t_parser *parser);
int				ft_redirs8(t_parser *parser);
int				ft_redirs_fin(t_parser *parser);
void			ft_redirs9(t_parser *parser);
void			ft_redir_do_func(t_parser *parser, char ***envp);
void			ft_pipes_redirs_init(t_parser *parser);
void			ft_pipes_and_redirs2(t_parser *parser, char **str);
void			ft_pipes_and_redirs3(t_parser *parser, char *str);
void			ft_check_argc(char **argv, int argc);
void			ft_init_main(t_parser *parser, t_func *func);
void			ft_choose_func(t_parser *parser, char ***envp);
void			ft_some_frees(t_parser *parser, char ***envp);
void			ft_start_of_cycle(t_parser *parser);
void			ft_prompt_and_oth(t_parser *parser);
void			ft_shlvl_and_inits(t_parser *parser,
				t_func *func, char ***envp);
void			ft_write_mess(t_parser *parser);
void			ft_choose_func2(t_parser *parser, char ***envp);
void			ft_check_env3_dop(t_parser *parser, char *envp,
				char **search, int *m);
void			ft_check_enc_del1_dop(t_parser *parser, int *k,
				char **search, int *j);
void			ft_in_quot_dop(t_parser *parser, int col, int *j);
void			ft_kon1(t_parser *parser, int sum1);
void			ft_flms(t_parser *parser, int *i);

extern t_sig g_sig;
#endif
