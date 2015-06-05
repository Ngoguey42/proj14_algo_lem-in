/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 18:06:34 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 18:27:56 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				li_print_route(t_env const *e, t_route const *r)
{
	size_t		i;

	i = 0;
	while (i < r->len)
	{
		if (i != 0)
			ft_putstr(", ");
		ft_putstr(ROOM_I(e->rooms, r->rooms[i])->name);
		i++;
	}
	ft_putchar('\n');
	return ;
}

void				li_print_routes(t_env const *e)
{
	size_t		i;

	i = 0;
	while (i < e->routes.size)
	{
		li_print_route(e, ROUTE_I(e->routes, i));
		i++;
	}
	qprintf("Num: %u\n", e->routes.size);
	return ;
}
