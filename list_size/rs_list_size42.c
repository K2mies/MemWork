/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_list_size42.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:10:29 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/23 16:18:01 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int		rs_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + rs_list_size(begin_list->next));
}

t_list	*rs_append_node(int data)
{
	t_list	*new_node = (t_list *)malloc(sizeof(t_list));
	new_node->data = (void *)(intptr_t)data;
	new_node->next = NULL;
	return (new_node);
}

void	rs_free_list(t_list *head)
{
	while(head)
	{
		t_list	*temp = head;
		head = head->next;
		free(temp);
	}
}

int		main(int argc, char **argv)
{
	int		i;
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
	printf("Test 01: size: %d\n", rs_list_size(head));
	rs_free_list(head);
}
