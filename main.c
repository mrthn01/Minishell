/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/16 12:50:17 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	char **envp:
		environment variables used for information about the user's home directory,
		terminal type, current locale, and ...
*/

// save environment variables in a minishell struct environment varaibles and pass it.
char	**ft_pass_envp_var(char **envp)
{
	char	**temp;
	int		i;

	i = 0;
	while(envp[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (envp[i])
		{
			temp[i] = ft_strdup(envp[i]);
			i++;
		}
	temp[i] = 0;
	return (temp);
}


// Initialize environment variable also customize minishell variables in here
void	ft_init_envp(char **envp, t_minishell *minishell)
{
	minishell->env = ft_pass_envp_var(envp);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_minishell	minishell;
	char		*input;

	ft_init_envp(envp, &minishell);
	while (1) 
	{
		input = readline("minishell$ ");
		parse_init(input, envp, &minishell); // parsing input
		add_history(input); // add history
	}
	return 0;
}
