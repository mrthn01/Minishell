/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:06:40 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/19 23:10:18 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_state	g_state;

// store environment variable and later access through global variable
char	**ft_store_envp(char **envp)
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

// init minishell states
void	ft_init(char **envp)
{
	g_state.envp = ft_store_envp(envp);
}
