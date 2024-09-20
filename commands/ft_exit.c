/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:57:32 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/19 23:26:58 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// exit command
void	ft_exit(t_minishell *mini)
{
	t_list	*temp;
	int		total_len;
	
	temp = mini->nodes_t;
	total_len = ft_lstsize(temp);
	if (total_len <= 3)
		exit(EXIT_SUCCESS);
	else
		printf("exit: too many arguments\n");
}
