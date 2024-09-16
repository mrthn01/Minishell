/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:18:01 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/16 15:41:52 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_control_envp_var(char *argv)
{
	if (ft_isdigit(*argv))
		return (0);
	return (1);
}

// free arrays
void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// check the equality sign on entered command
int	ft_check_equal_sign(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '=' || ft_isdigit(argv[0]))
		return (0);
	while (argv[i] && argv[i] != '=')
	{
		if (ft_isalnum(argv[i]) == 0)
			return (0);
		i++;
	}
	if (ft_updated_strchr(&argv[i], '=') == 1)
		return (1);
	return (0);
}

// check environmental exists. If it exists return index of environmental value, else return -1
int	ft_exists(char *argv, t_minishell *minishell)
{
	int	i;
	int	j;

	i = 0;
	while (minishell->env[i])
	{
		j = 0;
		while (minishell->env[i][j] && argv[j])
		{
			if (argv[j] == '=' && minishell->env[i][j] == '=')
				return (i);
			if (argv[j] != minishell->env[i][j])
				break;
			j++;
		}
		i++;
	}
	return (-1);
}

// return number of environment variables
int	ft_number_of_envp_var(char **envp)
{
	int	i;

	i = 0;
	while (*envp)
	{
		i++;
		envp++;
	}
	return (i);
}

// Display exported variables 
void	ft_display(char **envp)
{
	char	**temp;

	temp = envp;
	while (*temp)
	{
		printf("describe -x %s\n", *temp);
		temp++;
	}
}

// add new environment variable
void	ft_add_new_env(char *argv, t_minishell *minishell, char **envp)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = ft_calloc(sizeof(char *), ft_number_of_envp_var(envp) + 1);
	if (!new_env)
		return ;
	while (minishell->env[i])
	{
		new_env[i] = ft_strdup(minishell->env[i]);
		i++;
	}
	new_env[i] = ft_strdup(argv);
	ft_free_array(minishell->env);
	minishell->env = new_env;
}

// Update existing environment variable
void	ft_update_env(char *argv, t_minishell *minishell)
{
	int	location;

	location = ft_exists(argv, minishell);
	free(minishell->env[location]);
	minishell->env[location] = ft_strdup(argv);
}

// export command
void	ft_export(t_token *token, char ***envp, t_minishell *minishell)
{
	char	**argv;
	int		argc;
	
	argv = ft_get_char(token);
	argc = ft_strlen_adjusted(argv);
	if (argc == 1)
	{
		ft_display(minishell->env);
		return ;
	}
	while (*++argv)
	{
		printf("argv: %s\n", *argv);
		if (ft_check_equal_sign(*argv) == 0)
			continue ;
		printf("argv next: %s\n", *argv);
		if (*argv && ft_control_envp_var(*argv))
		{
			printf("It is working\n");
			if (ft_exists(*argv, minishell) != -1)
			{
				ft_update_env(*argv, minishell);
				printf("Updating is worked\n");
			}
			else
			{
				ft_add_new_env(*argv, minishell, *envp);
				printf("Adding new environment variable is worked\n");
			}
		}
	}
}
