/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_list_size26.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:48:01 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/17 12:52:40 by rhvidste         ###   ########.fr       */
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

t_list	*rs_create_node(int data)
{
	t_list	*new_node = (t_list *)malloc(sizeof(t_list));
	new_node->data = (void *)(intptr_t)data;
	new_node->next = NULL;
	return (new_node);
}

void	rs_free_list(t_list *head)
{
	while (head)
	{
		t_list *temp = head;
		head = head->next;
		free(temp);
	}
}

int		main() 
{
	t_list	*list1 = rs_create_node(1);
	list1->next = rs_create_node(2);
	list1->next->next = rs_create_node(3);
	list1->next->next->next = rs_create_node(4);
	printf("Test 01 (for elements) size : %d\n", rs_list_size(list1));
	rs_free_list(list1);
}
