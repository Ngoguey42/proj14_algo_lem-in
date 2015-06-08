/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:08:49 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/08 11:57:58 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>

static int					init_env(t_env *e)
{
	ft_bzero(e, sizeof(*e));
	if (ftv_init_instance(&e->rooms, sizeof(t_room)))
		return (1);
	return (0);
}

int							main(void)
{
	t_env	e;

	if (init_env(&e))
		return (DEBUG("init_env failed\n"), 1);
	if (li_parse(&e))
		return (DEBUG("parsing failed\n"), 1);
	li_put_anthill(&e);
	li_calc_routes(&e);
	li_print_routes(&e);	//debug
	if (e.routes.size == 0)
		return (DEBUG("No routes available\n"), 1);
	free(e.connections);
	e.connections = NULL;
	li_calc_combos(&e);
	li_print_bestcombo(&e);	//debug
	li_send_ants(&e);
	// send ants.
	// leave
	return (0);
}
