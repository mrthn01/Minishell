/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:27:28 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/18 16:51:08 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// unset (removing environment elements)
void	ft_remove_var(char *str)
{
	char	**updated_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	updated_env = ft_calloc(sizeof(char *), ft_number_of_envp_var() + 1);
	while (g_minishell.env[i])
	{
		if (ft_strncmp(g_minishell.env[i], str, ft_strlen(str)))
		{
			updated_env[j] = ft_strdup(g_minishell.env[i]);
			j++;
		}
		i++;
	}
	updated_env[j] = NULL;
	ft_free_array(g_minishell.env);
	g_minishell.env = updated_env;
}

void	ft_unset(char **input)
{
	char	*str;

	input++;
	while (*input)
	{
		str = ft_strjoin(*input, "=");
		ft_remove_var(str);
		free(str);
		input++;
	}
}
