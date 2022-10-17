/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:29:22 by alewalla          #+#    #+#             */
/*   Updated: 2022/08/21 14:16:27 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <pthread.h>
# include <sys/time.h>
# include <readline/readline.h>
# include <readline/history.h>
//# include <curses.h>
//# include <term.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>

#define OUT 0
#define IN_SINGLE 1
#define IN_DOUBLE 2
#define WORD 0
#define PIPE 1
#define INFILE 2
#define OUTFILE 3


typedef struct s_tok	t_tok;
struct s_tok
{
	char	*data;
	int		type;
	int		status;
	t_tok	*previous_link;
	t_tok	*next_link;
};

typedef struct s_env	t_env;
struct s_env
{
	char		*name;
	char		*value;
	t_env		*next_link;
};

typedef struct s_arg	t_arg;
struct s_arg
{
	char		*argument;
	int			nbr_arg;
	t_arg		*next;
};

typedef struct s_cmd	t_cmd;
struct s_cmd
{
	char		*cmd_user;
	int			*lenght_cmd;
	int			nbr;
	t_arg		*next_arg;
	t_cmd		*next_cmd;
};

typedef struct s_path	t_path;
struct s_path
{
	char	*path_env;
	char	**path_tab;
};

typedef struct s_core	t_core;
struct s_core
{
	t_env	*envl;
	t_path	*path;
};

void	ft_parsing(char *cmd_line, t_tok *token);
void	ft_putstruct(t_tok *token);
void	ft_setup_first_block(t_tok *token);
void	ft_create_word_block(t_tok *token, char data);
void	ft_create_type_block(t_tok *token, int type);
void	ft_create_quote_block(int status, t_tok *token);
void	ft_create_empty_block(t_tok *token);

void	ft_free_tokenl(t_tok *token);

//////

char	*alloc_line_char_read(char *line_read, int *i, char c);
char	**alloc_line_read(char **tab_line, char *line_read);
int		count_line_char_read1(char *line_read, int *i, int count, char c);
int		count_line_read(char *line_read);
char	**alloc_cmd(char *line_read);

void	ft_alloc_path_tab(t_core *core);

char	*ft_test_cmd(t_core *core, char *arg);

//t_list	*init_cmd(void);
//t_cmd	*add_nbr_cmd(t_list *tab_list, int new_nbr);
//void	delete_nbr_cmd(t_list *tab_list);
//void	print_cmd(t_list *tab_list);

t_arg	*init_arg(void);
t_arg	*add_nbr_arg(t_cmd *tab_list, int new_nbr);
void	delete_nbr_arg(t_cmd *tab_list);
void	print_arg(t_cmd *tab_list);

int		ft_get_len(int n);
char	*ft_create_str(int len, int n, int neg, char *str);
char	*ft_itoa(int n);
char	*alloc_line_char_read2(char *line_read, int *i);

char	*ft_create_str(int len, int n, int neg, char *str);
int		ft_get_len(int n);

int		ft_cd(int ac, char **av, t_env *envl);
int		ft_change_dir(char *name, t_env *envl);
int		ft_echo(int ac, char **arg);
int		ft_check_flags(char **arg);
void	ft_env(char **envp);
int		ft_pipe(char **f_input, char **f_ouput, char **envp);
void	ft_pwd(void);
char	*ft_getcwd(void);
int		ft_tab_len(char **tab);
void	ft_new_tab(char **dest, char *add);
int		ft_export(int ac, char **arg, t_env *envp);
void	ft_unset(char **arg, t_env *envl);
void	inthandler(int sig);

char	*ft_get_name(char *str, char stop);
char	*ft_get_value(char *str);
void	ft_join_value(t_env *envl, char *name, char *value);

void	ft_print_envl(t_env	*envl);
void	ft_envp_to_envl(char **envp, t_env *envl);
void	ft_add_to_envl(t_env *envl, char *name, char *value);
void	ft_remove_from_envl(t_env *envl, char *name);
void	ft_change_value(t_env *envl, char *name, char *value);
int		ft_is_in_envl(t_env *envl, char *name);
void	ft_free_envl(t_env *envl);
char	*ft_get_value_from_envl(t_env *envl, char *name);

char	*ft_replace_dollar(char *line, t_env *envl, int mode);

char	**ft_envl_to_envp(t_env *envl);
void	ft_free_envp(char **envp);

void	ft_exit(int nbr, t_env *envl, char **arg);

#endif