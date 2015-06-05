/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:13:54 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 16:19:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int             li_is_namechar(int c)
{
	if (!ft_isgraph(c) || c == '-')
		return (0);
	return (1);
}

static int			save_numants(t_env *e, t_line *l, t_bool *has_num_ants)
{
	if (*has_num_ants == true)
		return (1);
	e->num_ants = l->v1;
	*has_num_ants = true;
	return (0);
}

int				li_parse(t_env *e)
{
	int			err;
	t_line		line;
	t_linetype	prev_type;
	t_bool		has_num_ants;

	has_num_ants = false;
	prev_type = room;
	while ((err = li_parse_next_line(&line)) > 0)
	{
		if (line.type == connection && li_save_connection(e, &line))
			return (DEBUG("Error saving connection"), 1);
		else if (line.type == room)
		{
			if (e->connections != NULL)
				return (DEBUG("Room declared after connections"), 1);
			else if (li_save_room(e, &line, prev_type))
				return (DEBUG("Error saving room"), 1);
		}
		else if (line.type == numants && save_numants(e, &line, &has_num_ants))
			return (DEBUG("Error saving numants"), 1);
		if (line.type != comment && line.type != empty)
			prev_type = line.type;
	}
	return (DEBUG(err < 0 ? "Error in file" : "Reading OK"), err < 0 ? 1 : 0);
}
