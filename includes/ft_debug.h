/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 12:00:09 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 16:13:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

/*
** Privates
*/

# include "ft_typedefs.h"
# include "ft_vector.h"

typedef struct		s_debugline
{
	int				gid;
	int				count;
	int				logcount;
	int				line;
	char			func[64];
	char			file[64];
}					t_debugline;

typedef struct		s_debugdatas
{
	t_ftvector		lines;
	t_bool			init;
	t_bool			print;
}					t_debugdatas;

# define T dbg_printt(__FILE__, __FUNCTION__, __LINE__)

/*
** Privates
*/
void				dbg_printt(const char *file, const char *func, int line);
t_debugdatas		*dbg_instance(void);
void				dbg_printline(size_t gid);
/*
** Publics
*/
void				dbg_recap(void);
void				dbg_resetlog(void);
void				dbg_noprint(void);
void				dbg_doprint(void);

int					qprintf(const char *format, ...);
int					lprintf(const char *format, ...);

#endif
