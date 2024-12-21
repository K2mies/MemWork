/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_sort_list02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:16:31 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/21 14:42:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_sort_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*rs_sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*start;
	start	= lst;
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

int	rs_ascending(int a, int b)
{
	return (a <= b);
}

t_list	*rs_create_node(int data)
{
	t_list	*node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return (node);
}

void	rs_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

void	rs_free_list(t_list *lst)
{
	t_list	*tmp;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
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
			head = rs_create_node(atoi(argv[i]));
			current = head;
		}
		else 
		{
			current->next = rs_create_node(atoi(argv[i]));
			current = current->next;
		}
		i++;
	}
	printf("Origonal List: \n");
	rs_print_list(head);

	head = rs_sort_list(head, rs_ascending);

	printf("Sorted list: \n");
	rs_print_list(head);

	rs_free_list(head);

}
