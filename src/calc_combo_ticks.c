
#include "lemin.h"
#include <limits.h>
#include <stdlib.h>

/*
** 'li_combo_ticks'		computes the number of ticks needed for all ants to
**							reach the end, with the given routes combo.
*/

/*
** Scripting some calculations for 'combo_ticks' in the macros below.
** (This project being C only, i can't use any scripting language for this part)
*/
#define NUM_ROUTES			datas[4]
#define MIN_LEN				datas[0]
#define MAX_DIFF			datas[1]
#define SUM_DIFF			datas[2]
#define NUM_ANTS			(e->num_ants)
#define MIN_ANTS			datas[3]

static size_t		min(size_t const a, size_t const b)
{
	return (a < b ? a : b);
}

static size_t		ceildiv(size_t const a, size_t const b)
{
	size_t const	result = a / b;

	return (result * b == a ? result : result + 1u);
}

static inline void	build_datas(t_env const *e, int const *route_stack,
							int const stacki, size_t datas[5])
{
	int		i;
	size_t	tmp;

	i = 0;
	NUM_ROUTES = (size_t)stacki + 1u;
	MIN_LEN = -1;// MIN_LEN = UINT_MAX;
	while (i <= stacki)
		MIN_LEN = min(MIN_LEN, ROUTE_I(e->routes, route_stack[i++])->len);
	i = 0;
	MAX_DIFF = 0u;
	SUM_DIFF = 0u;
	while (i <= stacki)
	{
		tmp = ROUTE_I(e->routes, route_stack[i])->len - MIN_LEN;
		MAX_DIFF = MAX(MAX_DIFF, tmp);
		SUM_DIFF += tmp;
		i++;
	}
	MIN_ANTS = NUM_ROUTES * MAX_DIFF - SUM_DIFF;
	return ;
}

int					li_combo_ticks(t_env const *e, int const *route_stack,
							int const stacki)
{
	size_t			datas[5];

	build_datas(e, route_stack, stacki, datas);
	if (NUM_ANTS < MIN_ANTS)
		return (INT_MAX);
	return (ceildiv(NUM_ANTS - MIN_ANTS, NUM_ROUTES) + MAX_DIFF + MIN_LEN);
}
