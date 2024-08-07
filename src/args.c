/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:42:10 by paromero          #+#    #+#             */
/*   Updated: 2024/06/19 10:42:10 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add(t_stack	**head_ref, int new_value, int new_pos)
{
	t_stack	*new_node;
	t_stack	*last;
	int		index;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	last = *head_ref;
	new_node->value = new_value;
	new_node->pos = new_pos;
	new_node->index = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return ;
	}
	index = 1;
	while (last->next != NULL)
	{
		last = last->next;
		index++;
	}
	new_node->index = index;
	last->next = new_node;
}

int	hasduplicates(t_stack	*head)
{
	t_stack	*current;
	t_stack	*checker;

	current = head;
	while (current != NULL && current->next != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->value == checker->value)
			{
				ft_error();
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

// void one_arg(char *array, t_stack **head)
// {
// 	int i = 0;
// 	char *token = *ft_split(array, ' ');
// 	int pos = 0;

// 	while (token != NULL) {
// 		for (i = 0; token[i] != '\0'; i++)
// 		{
// 			if (token[i] < '0' || token[i] > '9')
// 			{
// 				ft_error();
// 			}
// 		}
// 		ft_add(head, atoi(token), pos);
// 		pos++;
// 		token = *ft_split(NULL, ' ');
// 	}
// }

void	one_arg(char *array, t_stack **head)
{
	char	**tokens;
	char	*token;
	int		j;
	int		pos;
	int		i;

	tokens = ft_split(array, ' ');
	j = 0;
	pos = 0;
	if (!tokens)
		ft_error();
	while (tokens[j] != NULL)
	{
		token = tokens[j];
		i = 0;
		while (token[i] != '\0')
		{
			if (token[i] < '0' || token[i] > '9')
			{
				ft_error();
			}
			i++;
		}
		ft_add(head, atoi(token), pos);
		pos++;
		j++;
	}
	j = 0;
	while (tokens[j] != NULL)
	{
		free(tokens[j]);
		j++;
	}
	free(tokens);
}

void	various_args(int ac, char **av, t_stack **head)
{
	int	i;
	int	j;
	int	pos;

	pos = 0;
	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j] != '\0')
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				ft_error();
			}
			j++;
		}
		ft_add(head, ft_atoi(av[i]), pos);
		pos++;
		i++;
	}
}

void	check_args(int ac, char **av, t_stack **head)
{
	if (ac == 2)
	{
		one_arg(av[1], head);
	}
	else if (ac > 2)
	{
		various_args(ac, av, head);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
