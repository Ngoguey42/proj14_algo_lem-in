/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:27:15 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/08 11:21:55 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTHILL_STRUCTS_S
# define ANTHILL_STRUCTS_S

# define START_ROOM_FLAG	0x1
# define END_ROOM_FLAG		0x2

# define ROOM_I(V, I) (((t_room*)(V).data) + (I))
# define ROUTE_I(V, I) (((t_route*)(V).data) + (I))
# define CONNECTION_ABVS(A,B,V,S) ((V) + (A) * (S) + (B))
# define CONNECTION_AB(A, B) (e->connections + (A) * e->rooms.size + (B))

typedef struct	s_room
{
	int			gid;
	char		*name;
	size_t		x;
	size_t		y;
	char		flags;
}				t_room;

typedef struct	s_route
{
	int			gid;
	int			*rooms;
	size_t		len;
}				t_route;

typedef struct	s_combo
{
	int			num_ticks;
	size_t		num_routes;
	int			*routes;
}				t_combo;

typedef struct	s_trafic
{
	int			gid;
	int			*rooms;
	size_t		len;
	int			*ants_id;
}				t_trafic;

#endif
