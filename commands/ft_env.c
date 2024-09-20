/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:56:38 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/19 23:05:33 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char	**input)
{
	char	**envp;

	envp = g_state.envp;
	if (input[1])
	{
		printf("error: No such file or directory.\n");
		return ;
	}
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
}
