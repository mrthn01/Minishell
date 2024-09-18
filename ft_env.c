/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:30:15 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/18 16:36:18 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char	**input)
{
	char	**envp;

	envp = g_minishell.env;
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
