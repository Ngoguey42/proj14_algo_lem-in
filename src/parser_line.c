/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:46:26 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 19:15:09 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <unistd.h>

static int		is_namechar(int c)
{
	if (!ft_isgraph(c) || c == '-')
		return (0);
	return (1);
}

static int		parse_connection(char *data, t_line *line)
{
	line->type = connection;
	data++;
	ft_skipntype(&data, &ft_isblank);
	if (!is_namechar(*data))
		return (free(line->ptr), -1);
	line->name2 = data;
	ft_skiptype(&data, &is_namechar);
	ft_skiptype(&data, &ft_isblank);
	if (*data != '\0')
		return (free(line->ptr), -1);
	return (1);
}

static int		parse_room(char *data, t_line *line)
{
	size_t	len;

	line->type = room;
	len = ft_parseuinteger(data, &line->v1);
	if (len == 0)
		return (free(line->ptr), -1);
	ft_skipntype(&data, &ft_isblank);
	len = ft_parseuinteger(data, &line->v2);
	if (len == 0)
		return (free(line->ptr), -1);
	ft_skipntype(&data, &ft_isblank);
	if (*data != '\0')
		return (free(line->ptr), -1);	
	return (1);
}

static int		parse_anthill_info(char *data, t_line *line)
{
	ft_skiptype(&data, &ft_isblank);
	line->name1 = data;
	ft_skiptype(&data, &is_namechar);
	ft_skiptype(&data, &ft_isblank);
	if (*data == '-')
		return (parse_connection(data, line));
	return (parse_room(data, line));
}

int				li_parse_next_line(t_line *line)
{
	char		*data;
	int			err;

	err = get_next_line(0, &line->ptr);
	data = line->ptr;
	if (err < 0)
		return (err);
	else if (err == 0 || (data[0] == '#' && data[1] != '#'))
		return (free(data), err);
	if (ft_strequ(data, "##end"))
	{
		line->type = endflag;
		return (free(data), 1);
	}
	else if (ft_strequ(data, "##start"))
	{
		line->type = startflag;
		return (free(data), 1);
	}	
	return (parse_anthill_info(data, line));
}
