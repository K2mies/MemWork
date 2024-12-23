/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_list_foreach10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:33:26 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/23 17:03:38 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_list.h"
#include <stdio.h>
#include <stdlib.h>

void	rs_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;

	}
}
