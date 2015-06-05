/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save_connection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 13:51:58 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 15:57:21 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			get_gids(size_t gid[2], t_ftvector const *v,
								char const *n1, char const *n2)
{
	size_t		i;
	size_t		j;
	t_room		*ptr;

	ptr = (t_room*)v->data;
	i = 0;
	j = 0;
	while (i < v->size && j < 2)
	{		
		if (ft_strequ(n1, ptr->name))
			gid[j++] = ptr->gid;
		else if (ft_strequ(n2, ptr->name))
			gid[j++] = ptr->gid;
		ptr++;
	}
	return (j != 2);
}


int					li_save_connection(t_env *e, t_line *l)
{
	size_t		gid[2];

	if (e->connections == NULL)
	{
		e->connections = ft_memalloc(
			sizeof(t_byte) * e->rooms.size * e->rooms.size);
		if (e->connections == NULL)
			return (1);
	}
	l->name1[ft_strlentype(l->name1, &li_is_namechar)] = '\0';
	l->name2[ft_strlentype(l->name2, &li_is_namechar)] = '\0';
	if (get_gids(gid, &e->rooms, l->name1, l->name2))
		return (DEBUG("Room name not found"), 1);
	free(l->ptr);
	*CONNECTION_AB(gid[0], gid[1]) = 1;
	*CONNECTION_AB(gid[1], gid[0]) = 1;
	return (0);
}
