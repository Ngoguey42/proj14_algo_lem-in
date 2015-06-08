
#include "lemin.h"
#include <limits.h>
#include <stdlib.h>

static t_bool	overlaps(t_env const *e, int const *route_stack,
							int const stacki, t_route const *route)
{
	size_t			i;
	int				j;
	t_route const	*route2;
	size_t			k;

	i = 0;
	while (i < route->len)
	{	// pour chaque salles de la 'route'
		j = 0;
		while (j <= stacki)
		{ // pour chaque routes de la stack
			route2 = ROUTE_I(e->routes, route_stack[j]);
			k = 0;
			while (k < route2->len) //pour chaque salles de la 'route2';
				if (route->rooms[i] == route2->rooms[k++])
					return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static void		recurse_entry_point(t_env *e, int *route_stack,
					int const stacki)
{
	size_t		i;
	int const	ticks = li_combo_ticks(e, route_stack, stacki);

	lprintf("(%d routes) %3d (%d) ", stacki + 1, ticks, e->best_combo.num_ticks);
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
		if (!overlaps(e, route_stack, stacki, ROUTE_I(e->routes, i)))
		{
			route_stack[stacki + 1] = (int)i;
			recurse_entry_point(e, route_stack, stacki + 1);
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
