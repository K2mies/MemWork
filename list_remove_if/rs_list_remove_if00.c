/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_list_remove_if00.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:04:55 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/13 13:31:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "rs_list.h"

void	rs_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return ;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		rs_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		cur = *begin_list;
		rs_list_remove_if(&cur->next, data_ref, cmp);
	}
}

int	cmp(void *data, void *ref)
{
	return (*(int*)data - *(int*)ref);
}

t_list	*create_node(int value)
{
	t_list *new = malloc(sizeof(t_list));
	int	*data = malloc(sizeof(int));
	*data = value;
	new->data = data;
	new->next = NULL;
	return (new);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d ", *(int*)list->data);
		list = list->next;
	}
	printf("\n");
}

void	free_list(t_list *list)
{
	while (list)
	{
		t_list *temp = list;
		list = list->next;
		free(temp->data);
		free(temp);
	}
}

int	main()
{
	t_list *list = create_node(1);
	list->next = create_node(2);
	list->next->next = create_node(3);
	list->next->next->next = create_node(2);
	list->next->next->next->next = create_node(4);

	printf("Original list: ");
	print_list(list);

	int ref = 2;

	//Test case 1: remove all 2's
	rs_list_remove_if(&list, &ref, cmp);
	printf("After removing 2: ");
	print_list(list);

	//free the list
	free_list(list);

	return (0);
}

