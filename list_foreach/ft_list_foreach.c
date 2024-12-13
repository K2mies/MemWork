/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:00:20 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/13 13:02:40 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

void	print_int(void *data)
{
	printf("%d ", *(int*)data);
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

int		main()
{
	t_list *list = create_node(1);
	list->next = create_node(2);
	list->next->next = create_node(3);

	printf("List contents: ");
	ft_list_foreach(list, print_int);
	printf("\n");

	free_list(list);
	return (0);
}
