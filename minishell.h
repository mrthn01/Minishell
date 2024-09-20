/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:07:13 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/20 00:18:06 by murathanelc      ###   ########.fr       */
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
#include <sys/wait.h>

typedef struct s_fd
{
	int				out;
	int				in;
	struct s_fd		*next;
}					t_fd;

typedef struct s_file
{
	char			*after;
	int				type;
	struct s_file	*next;
}					t_file;

typedef struct	s_parse
{
	char			**args;
	int				out_file;
	int				in_file;
	struct s_parse	*next;
	t_file			*file;
}					t_parse;

typedef struct	s_minishell
{
	t_list			*nodes_t;
	t_parse			**nodes_p;
	int				token_num;

}					t_minishell;

typedef struct s_state
{
	char	**envp;
}				t_state;

int			check_if_empty(char *str);

// initialize
void		adjsut_all(char *input);

// adjust quotes
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
t_list		*add_q_to_nodes(int *index, char *input, t_list *mini_list);
int			ft_find_next_q(int start, char *input);
t_list		*ft_getridof_q(t_list *nodes_t);
t_list		*ft_basic_q(t_list *nodes_t, int	len);

//tokenizations
int			parse_init(char *input);
t_minishell	*ft_tokanazition(char **str, t_minishell *mini);
void		ft_control_token(t_minishell *mini);
//char		*ft_split_with_redirect(t_list *mini, t_list **head);
//void		ft_spread(t_minishell *mini);
//int			ft_getsize(t_minishell *mini);

//parsing
t_minishell		*parse(int in_file, int out_file, t_minishell *mini);
t_parse			*init_cmd(int in_file, int out_file);
void			add_new_node(t_parse *current, t_parse **list);
t_parse			**handle_pipes(t_list **token, t_parse **old_current, t_parse **list);
void			adjust_redirecs(t_list **token, t_parse **current);
void			add_arguments(t_list **token, t_parse **current);

// util
void		ft_error();
int			ft_lstprint_t(t_minishell *mini);
int			ft_get_size_double_point(char **str);
void		ft_split_free(char **str);
void		del(void *content);
int			ft_strlen_adjusted(char **str);
char		*ft_strtok(char *str, char *delim);
char		*ft_tab_to_space(char *input);
void		print_error(char *arg, char *message, int exit_status);
t_minishell	*ft_deleteFirstNode(t_minishell *mini);
int			ft_controll_qoutes(char *str);
int			ft_updated_strchr(char *str, int c);
void		ft_init(char **envp);
char		**ft_store_envp(char **envp);

//redirect in token
int			ft_special_type_index(char c);
int			ft_special_type(char *input);
t_minishell	*ft_find_the_type(char *input, int start,int len, t_minishell *special,int *index_num);
t_minishell	*ft_get_redi_in(char *input, int start,int len, t_minishell *special, int *index_num);
t_minishell	*ft_get_redi_out(char *input, int start,int len, t_minishell *special, int *index_num);
t_minishell	*ft_get_pipe(char *input, int start, int len, t_minishell *mini, int *index_num);
t_minishell	*ft_get_redi_herodoc(char *input, int start,int len, t_minishell *special, int *index_num);
t_minishell	*ft_get_redi_append(char *input, int start,int len, t_minishell *special, int *index_num);
t_minishell	*ft_assign_special_type(t_minishell *mini);
t_minishell	*divide_accordingly(char *input, t_minishell *mini, int *index);
t_minishell	*ft_add_new_node(char *input, int start, int len, t_minishell *mini, int *index_num);

//	syntax controll

int			ft_syntax_check(t_minishell *mini);
int			fixed_check(t_list *tmp_token);
int			redic_check(t_list *tmp_token);
int			pipe_check(t_list *tmp_token, t_list *tmp_prev);

//	execute

void		ft_execute_commands(t_minishell *mini);
char		*ft_find_command_path(char *command);
void		ft_command(t_minishell *mini);
char		**ft_get_char(t_minishell *token);

//	commands

void	ft_cd(t_minishell *mini);
bool	ft_check_option_n(char *str, int i);
int		ft_check_option(char *str);
void	ft_echo(char **str);
void	ft_env(char	**input);
void	ft_exit(t_minishell *mini);
int		ft_check_envp_var(char *str);
int		ft_check_equal_sign(char *str);
void	ft_display_env(void);
int		ft_is_exist(char *str);
int		ft_number_of_envp_var(void);
void	ft_free_array(char **str);
void	ft_add_new_env(char *str);
void	ft_export(char **input);
void	ft_pwd(char *str);
void	ft_remove_var(char *str);
void	ft_unset(char **input);

extern t_state	g_state;

#endif