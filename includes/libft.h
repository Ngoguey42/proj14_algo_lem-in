/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:28:26 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 15:43:11 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>
# include "ft_typedefs.h"
# include "ft_macroes.h"
# include "ft_stdio.h"
# include "ft_stdlib.h"
# include "ft_ctype.h"
# include "ft_string.h"

void			ft_skiptype(char **pptr, int (*typefun)(int c));
void			ft_skipntype(char **pptr, int (*typefun)(int c));
size_t			ft_parseuinteger(char *str, size_t *uiptr);
size_t			ft_strlentype(char const *str, int (*typefun)(int c));

#endif
