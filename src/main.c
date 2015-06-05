/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:08:49 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 18:26:14 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int					init_env(t_env *e)
{
	ft_bzero(e, sizeof(e));
	ftv_init_instance(&e->rooms, sizeof(t_room));
	return (0);
}

int							main(void)
{
	t_env	e;

	if (init_env(&e))
		ft_putstr_fd("init_env failed\n", 2);
	if (li_parse(&e))
		ft_putstr_fd("parsing failed\n", 2);	
	li_put_anthill(&e);
	li_calc_routes(&e);
	li_print_routes(&e);
	// calc routes
	// if numroutes=0 exit
	// calc best routes combo
	// send ants.
	// leave
	return (0);
}
