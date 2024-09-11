/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:57:07 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/11 21:23:43 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	chdir function is used
	it changes the current working directory to path
*/

/*
	directory = getenv("HOME");
	Eğer cd yazarsam beni direk home'a yönlendiriyor
*/

void	ft_cd(t_token *token)
{
	char	**argv;
	char	*directory;
	int		total_len;
	
	argv = ft_get_char(token);
	total_len = ft_strlen_adjusted(argv);
	if (total_len < 2)
		directory = getenv("HOME");
	else
		directory = argv[1];
	printf("Success\n");
	if (chdir(directory) != 0)
		printf("cd: no such file or directory");
}
