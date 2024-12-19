/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_sort_list01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:48:50 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/19 15:06:07 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_sort_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		swap;
	t_list	*start;

	start = lst;

	while (lst != NULL && lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return (start);\
}

int	ascending(int a, int b)
{
	return (a <= b);
}

t_list	*new_node(int data)
{
	t_list	*node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

void	free_list(t_list *lst)
{
	t_list	*tmp;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int	main()
{
	t_list	*lst = new_node(3);
	lst->next = new_node(1);
	lst->next->next = new_node(4);
	lst->next->next->next = new_node(2);

	printf("Origonal list: ");
	print_list(lst);

	lst = sort_list(lst, ascending);

	printf("Sorted list: ");
	print_list(lst);

	t_list	*current = lst;
	while (current && current->next)
	{
		if (current->data > current->next->data)
		{
			printf("Test failed: list is not sorted. \n");
			free_list(lst);
			return (1);
		}
		current = current->next;
	}

	printf("Test Passed: List is sorted. \n");

	free_list(lst);

	return (0);
}
