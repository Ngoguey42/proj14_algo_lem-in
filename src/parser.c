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

int				li_parse(t_env *e)
{
	int			err;
	t_line		line;
	t_line		*line_alloced;

	if (ftv_init_instance(&e->lines, sizeof(t_line)))
		exit(1);
	while ((err = li_parse_next_line(&line)) > 0)
	{
		if (line.type != comment)
		{
			line_alloced = ft_memdup(&line, sizeof(t_line));
			if (line_alloced == NULL)
				exit(1);
			ftv_push_back(&e->lines, &line);
		}
	}
	if (err < 0)
		return (DEBUG("Error parsing file"), 1);
	return (DEBUG("Reading OK"), 0);
}
