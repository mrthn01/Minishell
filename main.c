/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/18 15:32:20 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_minishell;

/*
	char **envp:
		environment variables used for information about the user's home directory,
		terminal type, current locale, and ...
*/

// save environment variables in a minishell struct environment varaibles and pass it.
char	**ft_store_env_var(char **envp)
{
	char	**store_env;
	int		i;

	i = 0;
	while(envp[i])
		i++;
	store_env = malloc(sizeof(char *) * (i + 1));
	if (!store_env)
		return (0);
	i = 0;
	while (envp[i])
		{
			store_env[i] = ft_strdup(envp[i]);
			i++;
		}
	store_env[i] = 0;
	return (store_env);
}


// Initialize environment variable also customize minishell variables in here
void	ft_init_envp(char **envp)
{
	g_minishell.env = ft_store_env_var(envp);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char		*input;

	ft_init_envp(envp);
	while (1) 
	{
		input = readline("minishell$ ");
		parse_init(input, envp); // parsing input
		add_history(input); // add history
	}
	return 0;
}
