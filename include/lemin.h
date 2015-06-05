/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:10:15 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 19:25:09 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>

# include "libft.h"
# include "ft_debug.h" // debug, to remove


# define DEBUG(ARG) lprintf("%s", (ARG))

# include "anthill_structs.h"

/*
** Env
*/
typedef struct	s_env
{
	t_ftvector	rooms;
	t_byte		**connections;
	t_ftvector	routes;
}				t_env;

typedef enum	e_linetype
{
	empty = 0,
	comment,
	room,
	connection,
	startflag,
	endflag
}				t_linetype;

typedef struct	s_line
{
	t_linetype	type;
	size_t		v1;
	size_t		v2;
	char		*ptr;
	char		*name1;
	char		*name2;
}				t_line;
/*
** Core functions.
*/
/*
** Parsing functions.
*/
int			li_parse(t_env *e);
int			li_parse_next_line(t_line *line);

#endif
