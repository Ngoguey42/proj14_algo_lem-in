/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 11:40:28 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/08 12:55:35 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				li_print_action(t_env const *e, int antid, int roomid,
									t_bool reset)
{
	static t_bool		first = true;

	if (reset)
	{
		first = true;
		ft_putchar('\n');
		return ;
	}
	if (!first)
		ft_putchar(' ');
	first = false;
	ft_putchar('L');
	ft_putnbr(antid);
	ft_putchar('-');
	ft_putstr(ROOM_I(e->rooms, roomid)->name);
	return ;
}

void				li_forward_all_ants(t_env const *e, t_trafic *trafic)
{
	size_t		i;
	int			j;

	i = 0;
	while (i < e->best_combo.num_routes)
	{
		j = (int)trafic[i].len;
		while (j-- > 0)
		{
			if (trafic[i].ants_id[j] == -1)
				continue ;
			if (j == (int)trafic[i].len - 1)
				li_print_action(e, trafic[i].ants_id[j], e->endid, false);
			else
			{
				li_print_action(e, trafic[i].ants_id[j],
								trafic[i].rooms[j + 1], false);
				trafic[i].ants_id[j + 1] = trafic[i].ants_id[j];
			}
			trafic[i].ants_id[j] = -1;
		}
		i++;
	}
	return ;
}

void				li_insert_all_routes(t_env *e, t_trafic *trafic)
{
	size_t		i;

	i = 0;
	while (i < e->best_combo.num_routes)
	{
		trafic[i].ants_id[0] = ++e->ants_sent;
		li_print_action(e, e->ants_sent, trafic[i].rooms[0], false);
		i++;
	}
	return ;
}

void				li_insert_some_routes(t_env *e, t_trafic *trafic,
									int const itick, int const numticks)
{
	(void)e;
	(void)trafic;
	(void)itick;
	(void)numticks;
	return ;
}
