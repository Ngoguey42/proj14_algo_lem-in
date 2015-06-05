/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:13:54 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 19:17:16 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			save_room(t_env *e, t_line *l, t_linetype prev_type)
{
	(void)e;
	(void)l;
	(void)prev_type;
	return (0);
}

static int			build_connections_table(t_env *e)
{
	(void)l;
	return (0);
}

static int			save_connection(t_env *e, t_line *l)
{
	(void)build_connections_table;
	(void)e;
	(void)l;
	return (0);
}

int				li_parse(t_env *e)
{
	int			err;
	t_line		line;
	t_linetype	prev_type;

	if (ftv_init_instance(&e->lines, sizeof(t_line)))
		exit(1);
	prev_type = room;
	while ((err = li_parse_next_line(&line)) > 0)
	{
		if (line.type == connection)
			save_connection(e, line);
		else if (line.type == room)
			save_room(e, line, prev_type);
		if (line.type != comment && line.type != empty)
			prev_type = line.type;
	}
	if (err < 0)
		return (DEBUG("Error parsing file"), 1);
	return (DEBUG("Reading OK"), 0);
}
