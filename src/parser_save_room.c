/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 13:52:02 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 15:34:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

size_t				ft_strlentype(char const *str, int (*typefun)(int c))
{
	size_t	len;

	len = 0;
	while (typefun(*str++))
		len++;
	return (len);
}

static t_room		*alloc_room(t_env *e, t_line *l, t_linetype prev_type)
{
	t_room		*roomptr;

	if ((roomptr = malloc(sizeof(t_room))) == NULL)
		return (NULL);
	roomptr->gid = e->rooms.size;
	if ((roomptr->name = ft_strdup(l->name1)) == NULL)
		return (NULL);
	roomptr->x = l->v1;
	roomptr->y = l->v2;
	if (prev_type == startflag)
		roomptr->flags = START_ROOM_FLAG;
	if (prev_type == endflag)
		roomptr->flags = END_ROOM_FLAG;
	return (roomptr);
}

int					li_save_room(t_env *e, t_line *l, t_linetype prev_type)
{
	size_t		i;
	t_room		*roomptr;

	l->name1[ft_strlentype(l->name1, &li_is_namechar)] = '\0';
	i = 0;
	while (i < e->rooms.size)
	{
		roomptr = ROOM_I(e->rooms, i);		
		if (ft_strequ(l->name1, roomptr->name))
			return (DEBUG("Duplicated room name"), 1);
		else if (roomptr->x == l->v1 && roomptr->y == l->v2)
			return (DEBUG("Duplicated room position"), 1);
		else if (prev_type == startflag && roomptr->flags & START_ROOM_FLAG)
			return (DEBUG("Duplicated start room"), 1);
		else if (prev_type == endflag && roomptr->flags & END_ROOM_FLAG)
			return (DEBUG("Duplicated end room"), 1);
		i++;
	}
	roomptr = alloc_room(e, l, prev_type);
	free(l->ptr);
	if (roomptr == NULL || ftv_push_back(&e->rooms, roomptr))
		return (1);
	return (0);
}
