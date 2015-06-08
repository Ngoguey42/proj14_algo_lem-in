/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 11:40:28 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/08 11:59:25 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void				li_print_action(t_env const *e, int antid, int roomid)
{
	ft_putchar('L');
	ft_putnbr(antid);
	ft_putchar('-');
	ft_putstr(ROOM_I(e->rooms, roomid));
	return ;
}

void				li_forward_all_ants(t_env const *e, t_trafic *trafic)
{
	(void)e;
	(void)trafic;
	return ;
}

void				li_insert_all_routes(t_env const *e, t_trafic *trafic)
{
	(void)e;
	(void)trafic;
	return ;
}
