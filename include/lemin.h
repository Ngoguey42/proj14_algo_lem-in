/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:10:15 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/08 12:57:48 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>

# include "libft.h"
# include "ft_debug.h" // debug, to remove

# define DEBUG(ARG) lprintf("%s", (ARG)) //debug!!
# define DEBUGF(...) lprintf(__VA_ARGS__) //debug!!

# include "anthill_structs.h"

# define P1_FULL_SENDIND		phases[0]
# define P2_PARTIAL_SENDING		phases[1]
# define P3_SENDING_DONE		phases[2]

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
	int			ants_sent;
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
int			li_combo_ticks(t_env const *e, int const *route_stack,
							int const stacki);
void		li_combo_ticks_decomposed(t_env const *e, size_t phases[3]);
/*
** Ants sending functions.
*/
void		li_send_ants(t_env *e);
void		li_forward_all_ants(t_env const *e, t_trafic *trafic);
void		li_insert_all_routes(t_env *e, t_trafic *trafic);
void		li_insert_some_routes(t_env *e, t_trafic *trafic,
									int const itick, int const numticks);
void		li_print_action(t_env const *e, int antid, int roomid,
							t_bool reset);
/*
** Debug
*/
void		li_print_routes(t_env const *e);
void		li_print_bestcombo(t_env const *e);

#endif
