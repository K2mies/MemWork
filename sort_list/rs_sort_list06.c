/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_sort_list06.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:45:05 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/21 16:55:32 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_sort_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*rs_sort_list(t_list *list, int (*cmp)(int, int))
{
	int	swap;
	t_list	*start;
	start = list;
	while(list != NULL && list->next != NULL)
	{
		if ((*cmp)(list->data, list->next->data))
		{
			swap = list->data;
			list->data = list->next->data;
			list->next->data = swap;
			start = list;
		}
		else
		{
			list = list->next;
		}
	}
	return (start);
}

int	rs_ascending(int a, int b)
{
	return (a <= b);
}

t_list	*rs_append_node(int data)
{
	t_list	*new_node = (t_list *)malloc(sizeof(t_list));
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	rs_print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	printf("\n");
}

void	rs_free_list(t_list *head)
{
	t_list	*temp = head;
	head = head->next;
	free(temp);
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

	printf("Before sort:\n");
	rs_print_list(head);

	head = rs_sort_list(head, rs_ascending);
	printf("after asort: \n");
	rs_print_list(head);

	rs_free_list(head);
}
