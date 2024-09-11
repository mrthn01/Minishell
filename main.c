/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/11 23:27:31 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	char **envp:
		environment variables used for information about the user's home directory,
		terminal type, current locale, and ...
*/

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	*input;

	if (envp == NULL)
	{
		printf("Envp are null\n");
		return (1);
	}
	while (1) 
	{
		input = readline("minishell$ ");
		parse_init(input, envp); // parsing input
		add_history(input); // add history
	}
	return 0;
}
