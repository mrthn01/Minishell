/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:27:28 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/13 18:04:13 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Total number of environment variables
int	number_of_environment_arguments(char **envp)
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

// unset (removing environment elements)
void	unset(char *str, char **envp)
{
	char	**env;
	int		i;

	i = 0;
	env = malloc(sizeof(char *) * (number_of_environment_arguments(envp)) + 1);
	if (!env)
		return ;
	while (*envp)
	{
		if (ft_strncmp(*envp, str, ft_strlen(str)))
		{
			env[i] = ft_strdup(*envp);
			i++;
		}
		envp++;
	}
	env[i] = 0;
	envp = env;
}

void	ft_unset(t_token *token, char **envp)
{
	char	**argv;
	char	*str;

	argv = ft_get_char(token);
	argv++; // It is incremented because argv[0] == unset
	while (*argv)
	{
		str = ft_strjoin(*argv, "=");
		unset(str, envp);
		free(str);
		argv++;
	}
}
