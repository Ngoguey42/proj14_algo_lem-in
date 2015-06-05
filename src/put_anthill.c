/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_anthill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 16:23:41 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 18:25:53 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_rooms(t_ftvector const *v)
{
	size_t		i;

	i = 0;
	while (i < v->size)
	{
		if (ROOM_I(*v, i)->flags == START_ROOM_FLAG)
			ft_putendl("##start");
		if (ROOM_I(*v, i)->flags == END_ROOM_FLAG)
			ft_putendl("##end");
		ft_putstr(ROOM_I(*v, i)->name);
		ft_putchar(' ');
		ft_putnbr(ROOM_I(*v, i)->x);
		ft_putchar(' ');
		ft_putnbr(ROOM_I(*v, i)->y);
		ft_putchar('\n');
		i++;
	}
	return ;
}

static void		print_connections(t_byte const *c, size_t const n,
										t_room const *r)
{
	size_t		i;
	size_t		j;

	i = 0u;
	while (i < n - 1u)
	{
		j = i + 1u;
		while (j < n)
		{
			if (*CONNECTION_ABVS(i, j, c, n))
			{
				ft_putstr(r[i].name);
				ft_putchar('-');
				ft_putendl(r[j].name);
			}
			j++;
		}
		i++;
	}
	return ;
}

void			li_put_anthill(t_env const *e)
{
	ft_putnbr(e->num_ants);	
	ft_putchar('\n');
	print_rooms(&e->rooms);
	print_connections(e->connections, e->rooms.size, (t_room*)e->rooms.data);
	return ;
}
