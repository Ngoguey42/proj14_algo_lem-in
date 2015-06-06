/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 17:20:29 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 18:27:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_bool	is_available(t_env *e, int *room_stack, int stacki, int i)
{
	if (i == e->startid)
		return (false);
	while (stacki >= 0)
		if (i == room_stack[stacki--])
			return (false);
	return (true);
}

static t_bool	was_reachable_earlier(t_env const *e, int const *room_stack,
										int const stacki, int const roomi)
{
	int		i;

	i = 0;
	while (i <= stacki - 1)
	{
		if (*CONNECTION_AB(roomi, room_stack[i]))
			return (true);
		i++;
	}
	return (false);
}

static void		save_route(t_env *e, int *room_stack, int stacki)
{
	t_route		tmp;

	tmp.gid = e->routes.size;
	tmp.len = stacki + 1;
	tmp.rooms = (int*)ft_memdup(room_stack, sizeof(int) * tmp.len);
	if (tmp.rooms == NULL || ftv_push_back(&e->routes, &tmp))
		exit(1);
	return ;
}

static void		recurse_entry_point(t_env *e, int *room_stack, int const stacki)
{
	size_t		i;

	if (*CONNECTION_AB(room_stack[stacki], e->endid))
	{
		save_route(e, room_stack, stacki);
		return ;
	}
	i = 0;
	while (i < e->rooms.size)
	{
		if (*CONNECTION_AB(i, room_stack[stacki]) &&
			is_available(e, room_stack, stacki, (int)i) &&
			!was_reachable_earlier(e, room_stack, stacki, (int)i))
		{
			room_stack[stacki + 1] = (int)i;
			recurse_entry_point(e, room_stack, stacki + 1);
		}
		i++;
	}
	return ;
}

void			li_calc_routes(t_env *e)
{
	size_t			i;
	int				room_stack[e->rooms.size];

	ftv_init_instance(&e->routes, sizeof(t_route));
	i = 0;
	while (i < e->rooms.size)
	{
		if (*CONNECTION_AB(e->startid, i))
		{
			room_stack[0] = i;
			recurse_entry_point(e, room_stack, 0);
		}
		i++;
	}
	return ;
}
