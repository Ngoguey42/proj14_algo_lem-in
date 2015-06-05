/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_capacity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 18:37:27 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 15:32:40 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "ft_vector.h"
#include "ft_stdlib.h"

int					ftv_reserve(t_ftvector *v, size_t newcapacity)
{
	v->data = ft_realloc(v->data, v->size * v->chunk_size,
						newcapacity * v->chunk_size);
	v->capacity = newcapacity;
	if (v->data == NULL)
		return (ENOMEM);
	return (0);
}

int					ftv_shrink_to_fit(t_ftvector *v)
{
	v->data = ft_realloc(v->data, v->size * v->chunk_size,
							v->size * v->chunk_size);
	v->capacity = v->size;
	if (v->data == NULL)
		return (ENOMEM);
	return (0);
}
