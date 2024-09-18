/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:27:59 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/18 16:47:45 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtin_commands(t_token *token)
{
	char	*str;
	char	**input;

	input = ft_get_char(token);
	str = (char *)token->nodes_t->content;
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		ft_pwd(str);
	else if (ft_strncmp(str, "echo", ft_strlen(str)) == 0)
		ft_echo(token);
	else if (ft_strncmp(str, "cd", ft_strlen("cd")) == 0)
		ft_cd(token);
	else if (ft_strncmp(str, "env", ft_strlen("env")) == 0)
		ft_env(input);
	else if (ft_strncmp(str, "export", ft_strlen("export")) == 0)
		ft_export(input);
	else if (ft_strncmp(str, "unset", ft_strlen("unset")) == 0)
		ft_unset(input);
	else if (ft_strncmp(str, "exit", ft_strlen(str)) == 0)
		ft_exit(token);
}

void	ft_pwd(char *str)
{
	char	*pwd;
	
	if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
	{
		pwd = getcwd(NULL, 0);
		if (pwd != NULL)
		{
			printf("%s\n", pwd);
			free(pwd);
		}
		else
			perror("pwd error");
	}
	else
		return ;
}

void	ft_exit(t_token *token)
{
	t_list	*temp;
	int		total_len;
	
	temp = token->nodes_t;
	total_len = ft_lstsize(temp);
	if (total_len <= 3)
		exit(EXIT_SUCCESS);
	else
		printf("exit: too many arguments\n");
}
