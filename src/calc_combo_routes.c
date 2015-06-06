
#include "lemin.h"
#include <limits.h>
#include <stdlib.h>

static int		combo_ticks(t_env const *e, int const *route_stack,
							int const stacki)
{
	int		ticks;

	ticks = 0;
	return (ticks);
}

static t_bool	can_cohabit(t_env const *e, int const *route_stack,
							int const stacki, t_route const *route)
{
	
	return (true);
}

static void		recurse_entry_point(t_env *e, int *route_stack,
					int const stacki)
{
	size_t		i;
	int const	ticks = combo_ticks(e, route_stack, stacki);

	if (ticks < e->best_combo.num_ticks)
	{
		e->best_combo.num_ticks = ticks;
		e->best_combo.num_routes = stacki + 1;
		ft_memcpy(e->best_combo.routes, route_stack,
			sizeof(int) * (stacki + 1));
	}
	i = (size_t)route_stack[stacki] + 1;
	while (i < e->routes.size)
	{
		if (can_cohabit(e, route_stack, stacki, ROUTE_I(e->routes, i)))
		{
			route_stack[stacki + 1] = (int)i;
			recurse_entry_point((e, route_stack, stacki + 1);
		}
		i++;
	}
	return ;
}

void			li_calc_combos(t_env *e)
{
	size_t			i;
	int				route_stack[e->routes.size];

	e->best_combo.num_ticks = INT_MAX;
	e->best_combo.num_routes = 0;
	e->best_combo.routes = malloc(sizeof(int) * e->routes.size);
	if (e->best_combo.routes == NULL)
		exit(1);
	i = 0;
	while (i < e->routes.size)
	{
		route_stack[0] = i;
		recurse_entry_point(e, route_stack, 0);
		i++;
	}
	return ;
}
