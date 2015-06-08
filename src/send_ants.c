/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 10:57:39 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/08 13:00:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void					init_trafic(t_env const *e, t_trafic *trafic)
{
	size_t		i;
	size_t		j;
	t_route		*ref;

	i = 0;
	while (i < e->best_combo.num_routes)
	{
		ref = ROUTE_I(e->routes, e->best_combo.routes[i]);
		ft_memcpy(&trafic[i], ref, sizeof(t_route));
		trafic[i].ants_id = malloc(sizeof(int) * ref->len);
		if (trafic[i].ants_id == NULL)
			exit(1);
		j = 0;
		while (j < ref->len)
			trafic[i].ants_id[j++] = -1;
		i++;
	}
	return ;
}

static void					release_trafic(t_env const *e, t_trafic *trafic)
{
	size_t		i;

	i = 0;
	while (i < e->best_combo.num_routes)
		free(trafic[i++].ants_id);
	return ;
}

void				li_send_ants(t_env *e)
{
	size_t					phases[3];
	t_trafic				trafic[e->best_combo.num_routes];
	size_t					i;

	li_combo_ticks_decomposed(e, phases);
	T;
	DEBUGF("p1(%u), p1(%u), p1(%u)", phases[0], phases[1], phases[2]);
	init_trafic(e, trafic);
	T;
	i = 0;
	while (i++ < P1_FULL_SENDIND)
		li_forward_all_ants(e, trafic),
			li_insert_all_routes(e, trafic),
			li_print_action(e, 0, 0, true);
	T;
	i = 0;
	while (i++ < P2_PARTIAL_SENDING)
		li_forward_all_ants(e, trafic),
			li_insert_some_routes(e, trafic, i - 1, P2_PARTIAL_SENDING),
			li_print_action(e, 0, 0, true);
	T;
	i = 0;
	while (i++ < P3_SENDING_DONE)
		li_forward_all_ants(e, trafic),
			li_print_action(e, 0, 0, true);
	release_trafic(e, trafic);
	return ;
}
