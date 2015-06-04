/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 18:25:20 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 11:57:32 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <errno.h>
#include <stdlib.h>

int					ftv_init_instance(t_ftvector *v, size_t chunk_size)
{
	v->data = malloc(chunk_size * FT_VECTOR_DEFAULT_CAPACITY);
	if (v->data == NULL)
		return (ENOMEM);
	v->size = 0;
	v->chunk_size = chunk_size;
	v->capacity = FT_VECTOR_DEFAULT_CAPACITY;
	return (0);
}

t_ftvector			*ftv_init_alloc(size_t chunk_size)
{
	t_ftvector	*ret;

	ret = malloc(sizeof(t_ftvector));
	if (ret == NULL)
		return (NULL);
	if (ftv_init_instance(ret, chunk_size))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
