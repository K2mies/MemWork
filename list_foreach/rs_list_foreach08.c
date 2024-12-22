/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_list_foreach08.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:21:39 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/22 17:30:54 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_list.h"
#include <stdio.h>
#include <stdlib.h>

void	rs_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

void	rs_print_int(void *data)
{
	printf("%d ", *(int *)data);
}

t_list	*rs_append_node(int value)
{
	t_list	*new_node = (t_list *)malloc(sizeof(t_list));
	int	*data = malloc(sizeof(int));
	*data = value;
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	rs_free_list(t_list *head)
{
	while (head)
	{
		t_list	*temp = head;
		head = head->next;
		free(temp->data);
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_list	*head = NULL;
	t_list	*current = NULL;

	i = 1;
	while (i < argc)
	{
		if (head == NULL)
		{
			head = rs_append_node(atoi(argv[i]));
			current = head;
		}
		else
		{
			current->next = rs_append_node(atoi(argv[i]));
			current = current->next;
		}
		i++;
	}
	printf("OUTPUT: \n");
	rs_list_foreach(head, rs_print_int);

	rs_free_list(head);
}
