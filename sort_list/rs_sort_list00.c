/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_sort_list00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:27:36 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/16 16:01:51 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "rs_sort_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swap;
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
	return (start);
}

//comparison function
int	ascending(int a, int b)
{
	return (a <= b);
}

//function to create a new node
t_list	*new_node(int data)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return node;
}

// Function to print the list
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

// Function to free the list
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
	//create an unsorted list
	t_list	*lst = new_node(3);
	lst->next = new_node(1);
	lst->next->next = new_node(4);
	lst->next->next->next = new_node(2);

	printf("Origonal list: ");
	print_list(lst);

	//sort the list
	lst = sort_list(lst, ascending);

	printf("Sorted list: ");
	print_list(lst);

	//check if the list is sorted
	t_list	*current = lst;
	while (current && current->next)
	{
		if (current->data > current->next->data)
		{
			printf("Test failed: List is not sorted.\n");
			free_list(lst);
			return 1;
		}
		current = current->next;
	}

	printf("Test passed: List is sorted.\n");

	//free the list
	free_list(lst);

	return 0;
}
