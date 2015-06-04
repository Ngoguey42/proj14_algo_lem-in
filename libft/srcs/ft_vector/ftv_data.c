/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 11:31:39 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 19:22:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "ft_vector.h"
#include "ft_stdlib.h"
#include "ft_string.h"

t_bool		ftv_empty(t_ftvector const *v)
{
	return (v->size == 0);
}

int			ftv_push_back(t_ftvector *v, void const *ptr)
{
	if (v->size >= v->capacity)
	{
		v->capacity = v->size * 2;
		v->data = ft_realloc(v->data, v->size, v->capacity);
		if (v->data == NULL)
			return (ENOMEM);
	}
	ft_memcpy(v->data + v->size * v->chunk_size,
				ptr, v->chunk_size);
	v->size++;
	return (0);
}

void		ftv_assign(t_ftvector *v, void const *ref)
{
	size_t		i;

	i = 0;
	while (i < v->size)
	{
		ft_memcpy(v->data + i * v->chunk_size,
					ref, v->chunk_size);
		i++;
	}
}

int			ftv_insert(t_ftvector *v, void const *ref, size_t count)
{
	size_t		i;

	if (v->size + count >= v->capacity)
	{
		while (v->capacity <= v->size + count)
			v->capacity *= 2;
		v->data = ft_realloc(v->data, v->size, v->capacity);
		if (v->data == NULL)
			return (ENOMEM);
	}
	i = 0;
	while (i < v->size)
	{
		ft_memcpy(v->data + v->size * v->chunk_size + i * v->chunk_size,
					ref, v->chunk_size);
		i++;
	}
	v->size += count;
	return (0);
}
