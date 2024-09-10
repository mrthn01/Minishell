/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murathanelcuman <murathanelcuman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:04:05 by sebasari          #+#    #+#             */
/*   Updated: 2024/09/10 17:47:47 by murathanelc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_control_token(t_token *token)
{
	int			i;
	char		*str;
	t_list		*tmp;
	t_quote		*quotes;
	t_special	*special;

	quotes = malloc(sizeof(t_quote));
	quotes->nodes_q = malloc(sizeof(t_list));
	quotes->nodes_q->next = NULL;
	special = malloc(sizeof(t_special));
	special->nodes_s = malloc(sizeof(t_list));
	quotes->nodes_q->next = NULL;
	tmp = token->nodes_t;
	while (tmp -> next != NULL)
	{
		str = (char *)tmp->content;
		i = 0;
		while (str[i])
		{
			if (ft_is_quotes_there_index(str[i])) {
				printf("gecti 1\n");
				quotes = add_q_to_nodes(&i, str, quotes);
			}
			if (ft_special_type(str, i)) {
				printf("gecti 2\n");
				special = ft_find_the_type(str, i, special);
			}
			i++;
		}
		tmp = tmp->next;
	}
	// ft_command(token);
	// token = ft_free_undesired(token);
}

int	parse_init(char *input)
{
	char		**str;
	t_token		*token;

	token = malloc(sizeof(t_token));
	token->nodes_t = malloc(sizeof(t_token));
	token->nodes_t->next = NULL;
	input = ft_strtrim(input, " ");
	str = ft_split(input, ' ');
	token = ft_tokenazition(str, token); // Tokenazition I guess
	// execute command
	ft_execute_command(token);
	ft_split_free(str);
	ft_lstprint_t(token);
	ft_control_token(token);
	return (0);
}

t_token	*ft_tokenazition(char **str, t_token *token)
{
	int	i;
	t_list *new;

	i = ft_strlen_adjusted(str) - 1;
	while (i >= 0)
	{
		new	= ft_lstnew(str[i]);
		ft_lstadd_front(&token->nodes_t, new);
		token->nodes_t->content = malloc((ft_strlen(str[i]) + 1) * sizeof(char));
		ft_strlcpy(token->nodes_t->content, str[i], ft_strlen(str[i]) + 1);
		i--;
	}
	return (token);
}



// özel karakterler de sıkıntı var 
/*t_token	*ft_free_undesired(t_token *token)
{
	t_list	*tmp;
	t_list	*tmp_pre;
	char	*str;
		Check if token or token->nodes_t is null
	if (!token && token->nodes_t)
		return token;
	tmp = token->nodes_t;
	str = (char *)tmp->content;
		Check if the first node matches undesired conditions
	
	if (str && (ft_is_quotes_there_index(str[0]) || ft_special_type(str, 0)))
	{
		token->nodes_t = tmp->next;
		ft_lstdelone(tmp, del);
		ft_lstprint_t(token);
		return (token);
	}
		Initialize pointers to traverse the list
	tmp_pre = tmp;
	tmp = tmp_pre->next;
	str = (char *)tmp->content;
	while (tmp != NULL)
	{

			If we find undesired token, remove it
		if (str && (ft_is_quotes_there_index(str[0]) || ft_special_type(str, 0)))
		{
			tmp_pre->next = tmp->next;
			ft_lstdelone(tmp, del);
			return (token);
		}
		tmp_pre = tmp; // Move to next node
		tmp = tmp->next;
	}
	return (token);
}*/
