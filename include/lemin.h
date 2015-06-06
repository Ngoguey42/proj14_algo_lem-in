/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:10:15 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 18:16:02 by ngoguey          ###   ########.fr       */
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
	size_t		num_ants;
	t_ftvector	rooms;
	int			startid;
	int			endid;
	t_byte		*connections;
	t_ftvector	routes;
	t_combo		best_combo;
}				t_env;

typedef enum	e_linetype
{
	empty = 0,
	comment,
	numants,
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
void		li_put_anthill(t_env const *e);
/*
** Parsing functions.
*/
int			li_parse(t_env *e);
int			li_parse_next_line(t_line *line);
int			li_save_connection(t_env *e, t_line *l);
int			li_save_room(t_env *e, t_line *l, t_linetype prev_type);
int			li_is_namechar(int c);
/*
** Routes calculation functions.
*/
void		li_calc_routes(t_env *e);
/*
** Routes combo calculation functions.
*/
void		li_calc_combos(t_env *e);
/*
** Debug
*/
void		li_print_routes(t_env const *e);

#endif
