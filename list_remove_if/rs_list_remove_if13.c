/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_list_remove_if13.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:42:40 by rhvidste          #+#    #+#             */
/*   Updated: 2025/01/03 10:53:19 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_list.h"
#include <stdio.h>
#include <stdlib.h>

void	rs_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return ;
	t_list	*current = *begin_list;
	if ((*cmp)(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
		rs_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		current = *begin_list;
		rs_list_remove_if(&current->next, data_ref, cmp);
	}
}

int	cmp(void *data, void *ref)
{
	return(*(int *)data - *(int *)ref);
}

void	rs_print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", *(int *)list->data);
		list = list->next;
	}
	printf("\n");
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
	int	 i = 1;
	t_list *head = NULL;
	t_list *current = NULL;

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
	printf("Before Remove: \n");
	rs_print_list(head);
	int	ref = atoi(argv[1]);
	rs_list_remove_if(&head, &ref, cmp);
	printf("After Remove: \n");
	rs_print_list(head);
	rs_free_list(head);
}
