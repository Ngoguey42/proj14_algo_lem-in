/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:27:15 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 17:32:45 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTHILL_STRUCTS_S
# define ANTHILL_STRUCTS_S

typedef struct  s_room
{
	int			gid;
	char		*name;
	int			x;
	int			y;
	char		flags;
}               t_room;

typedef struct  s_route
{
	int			gid;
	int			*rooms;
}               t_route;

#endif
