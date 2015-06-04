/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:08:49 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 19:17:57 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int					init_env(t_env *e)
{
	ft_bzero(e, sizeof(e));
	return (0);
}

int							main(void)
{
	t_env	e;

	if (init_env(&e))
		ft_putstr_fd("init_env failed\n", 2);
	if (li_parse(&e))
		ft_putstr_fd("parsing failed\n", 2);	
	return (0);
}
