/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:01:06 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/19 21:01:07 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cd command
void	ft_cd(t_minishell *mini)
{
	char	**argv;
	char	*directory;
	int		total_len;
	
	argv = ft_get_char(mini);
	total_len = ft_strlen_adjusted(argv);
	if (total_len < 2)
		directory = getenv("HOME");
	else
		directory = argv[1];
	printf("Success\n");
	if (chdir(directory) != 0)
		printf("cd: no such file or directory");
}
