/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_flood_fill00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:31:45 by rhvidste          #+#    #+#             */
/*   Updated: 2024/12/20 19:06:47 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rs_flood_fill.h"
#include <stdlib.h>
#include <stdio.h>


void	rs_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	rs_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	rs_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	rs_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	rs_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	rs_flood_fill(char **tab, t_point size, t_point begin)
{
	rs_fill(tab, size, begin, tab[begin.y][begin.x]);
}
