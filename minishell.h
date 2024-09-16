/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:07:13 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/16 14:34:07 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_white
{
	t_list	*nodes_w;
}			t_white;

typedef struct s_special
{
	t_list	*nodes_s;
}			t_special;

typedef struct s_quote
{
	t_list	*nodes_q;
}			t_quote;

typedef struct s_token
{
	t_list	*nodes_t;
	char	**full_cmd;
}			t_token;
// Buraya shell'in ortak özelliklerini ve flaglerini ekleriz kontrol için
// ex: pipe, exit status, error...
typedef struct s_minishell
{
	char	**env;
}			t_minishell;


int			ft_single_quotes_finised(char *input, int index);
int			ft_quotes_num(char *input);
int			ft_is_quotes_there(char *input);
int			ft_is_quotes_there_index(char c);
int			ft_quotes(char *input);
int			ft_last_index_check(char *str);
void		ft_dollar_sign(char *str);
void		ft_back_slash(char *str);
int			ft_double_quotes_check(char *str, int index);
int			ft_double_quotes_finised(char *input, int index);
int			ft_even_odd(char *str, char c);
t_quote		*add_q_to_nodes(int *index, char *input, t_quote *quotes);
int			ft_find_next_q(int start, char *input);

// main.c util functions
void	ft_init_envp(char **envp, t_minishell *minishell);
char	**ft_pass_envp_var(char **envp);

int			parse_init(char *input, char **envp, t_minishell *minishell);
t_token		*ft_tokenazition(char **str, t_token *token);
void		ft_control_token(t_token *token);
t_token		*ft_free_undesired(t_token *token);

//-----Utils----------
void		ft_error();
void		ft_lstprint(t_quote *quotes);
void		ft_lstprint_s(t_special *special);
void		ft_lstprint_w(t_white *white);
void		ft_lstprint_t(t_token *token);
int			ft_get_size_double_point(char **str);
void		ft_split_free(char **str);
void		del(void *content);
int			ft_strlen_adjusted(char **str);
void		ft_count_environment(char **envp);
int			ft_updated_strchr(char *str, int c);

int			ft_special_type(char *input, int i);
t_special	*ft_find_the_type(char *input, int i, t_special *special);
t_special	*ft_get_redi_in(t_special *special, char *input, int i);
t_special	*ft_get_redi_out(t_special *special, char *input, int i);
t_special	*ft_get_pipe(t_special *special, char *input, int i);
t_special	*ft_get_redi_herodoc(t_special *special);
t_special	*ft_get_redi_append(t_special *special);

void		ft_execve(t_list *token);
void		ft_command(t_token *token, char **envp, t_minishell *minishell);
void		ft_execute_commands(t_token *token);
char		*ft_find_command_path(char *command);

// builtins
void		ft_builtin_commands(t_token *token, char **envp, t_minishell *minishell);
void		ft_pwd(char *str);
void		ft_echo(t_token *token);
void		ft_exit(t_token *token);
char		**ft_get_char(t_token *token);
void		ft_cd(t_token *token);
void		ft_env(char **envp);
void		ft_export(t_token *token,char ***envp, t_minishell *minishell);
void		ft_unset(t_token *token, char **envp);

// export utils
int			ft_check_equal_sign(char *argv);
int			ft_exists(char *argv, t_minishell *minishell);
int			ft_number_of_envp_var(char **envp);
void		ft_display(char **envp);
void		ft_update_env(char *argv, t_minishell *minishell);
void		ft_free_array(char **str);
void		ft_add_new_env(char *argv, t_minishell *minishell, char **envp);
int			ft_control_envp_var(char *argv);


#endif
