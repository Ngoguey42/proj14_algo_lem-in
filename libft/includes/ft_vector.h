/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 16:34:05 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 12:09:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# define FT_VECTOR_DEFAULT_CAPACITY		4

# include "ft_typedefs.h"

typedef struct	s_ftvector
{
	void		*data;
	size_t		size;
	size_t		capacity;
	size_t		chunk_size;
}				t_ftvector;

/*
** * Initialization functions **
** *
** 'ftv_init_instance'	Does the very first allocation of 'data' in v.
** 'ftv_init_alloc'		Does the very first allocation of 'data' and allocs v.
*/
int				ftv_init_instance(t_ftvector *v, size_t chunk_size);
t_ftvector		*ftv_init_alloc(size_t chunk_size);

/*
** * Destruction functions **
** *
** 'ftv_release'		Calls 'del' on each if not NULL, then calls free
**							on data.
** 'ftv_pop_back'		Calls 'del' on last if not NULL, then decreases 'size'.
** 'ftv_clear'			Calls 'del' on each if not NULL, then sets 'size' to 0.
** *
*/
void			ftv_release(t_ftvector *v, void (*del)(void*));
void			ftv_pop_back(t_ftvector *v, void (*del)(void*));
void			ftv_clear(t_ftvector *v, void (*del)(void*));

/*
** * Capacity functions **
** *
** 'ftv_reserve'		Reallocates 'data' to 'newcapacity'.
** 'ftv_shrink_to_fit'	Reallocates 'data' to 'size'.
*/
int				ftv_reserve(t_ftvector *v, size_t newcapacity);
int				ftv_shrink_to_fit(t_ftvector *v);

/*
** * Data functions **
** *
** 'ftv_empty'			Returns boolean whether #(size) > 0 or not.
** 'ftv_push_back'		Copies the #(chunk_size) first bytes pointed by ptr
**							at the back of data, may reallocate data.
** 'ftv_assign'			Assigns #(chunk_size) bytes pointed by ptr
** 							to all #(size) chunks.
** 'ftv_insert'			Copies #(count) times the #(chunk_size) first bytes
** 							pointed by ptr at the back of data, may reallocate
** 							data.
*/
t_bool			ftv_empty(t_ftvector const *v);
int				ftv_push_back(t_ftvector *v, void const *ptr);
void			ftv_assign(t_ftvector *v, void const *ref);
int				ftv_insert(t_ftvector *v, void const *ref, size_t count);

#endif
