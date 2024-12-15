/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_list_size05.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:34:03 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/15 18:39:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int	rs_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + rs_list_size(begin_list->next));
}

t_list	*create_node(int data)
{
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	new_node->data = (void *)(intptr_t)data;
	new_node->next = NULL;
	return (new_node);
}

void	free_list(t_list *head)
{
	while (head != NULL)
	{
		t_list *temp = head;
		head = head->next;
		free(temp);
	}
}

int	main()
{
	t_list *list1 = create_node(1);
	list1->next = create_node(2);
	list1->next->next = create_node(3);
	list1->next->next->next = create_node(4);
	printf("Test 01 (four elements): size = %d\n", rs_list_size(list1));
	free_list(list1);
}
