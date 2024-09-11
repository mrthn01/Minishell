/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:34:55 by murathanelc       #+#    #+#             */
/*   Updated: 2024/09/11 21:06:46 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_echo(char **argv, int argc, int i)
{
	while (i < argc)
	{
		printf("%s", argv[i]);
		if (i < argc - 1)
			printf(" ");
		i++;
	}
}

static int	ft_echo_flag(t_token *token)
{
	t_list	*temp;

	temp = token->nodes_t;
	while (temp->next != NULL)
	{
		if (ft_strncmp((char *)temp->content, "-n", 2) == 0 && ft_strlen((char *)temp->content) == 2)
			return (1);
		temp = temp->next;
	}
	return (0);
}

char	**ft_get_char(t_token *token)
{
	char	**argv;
	t_list	*temp;
	int		argc;
	int		i;
	
	temp = token->nodes_t;
	argc = 0;
	i = 0;
	while (temp)
	{
		argc++;
		temp = temp->next;
	}
	temp = token->nodes_t;
	argv = malloc((argc + 1) *  sizeof(char *));
	if (!argv)
		return (NULL);
	while (i < argc && temp != NULL)
	{
		argv[i] = (char *)temp->content;
		temp = temp->next;
		i++;
	}
	argv[argc] = NULL;
	return (argv);
}

void	ft_echo(t_token *token)
{
	char	**argv;
	int		i;
	int		total_len;
	bool	flag;

	argv = ft_get_char(token);
	total_len = ft_strlen_adjusted(argv);
	printf("deneme\n");
	flag = ft_echo_flag(token);
	if (flag)
	{
		i = 2;
		ft_print_echo(argv, total_len, i);
		printf("%%\n");
	}
	else
	{
		i = 1;
		ft_print_echo(argv, total_len, i);
		printf("\n");
	}
	free(argv);
}
