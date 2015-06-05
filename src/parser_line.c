/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:46:26 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 16:13:37 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <unistd.h>

static int		parse_connection(char *data, t_line *line)
{
	line->type = connection;
	data++;
	ft_skiptype(&data, &ft_isblank);
	if (!li_is_namechar(*data))
		return (free(line->ptr), -1);
	line->name2 = data;
	ft_skiptype(&data, &li_is_namechar);
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
	data += len;
	ft_skiptype(&data, &ft_isblank);
	len = ft_parseuinteger(data, &line->v2);
	if (len == 0)
		return (free(line->ptr), -1);
	data += len;
	ft_skipntype(&data, &ft_isblank);
	if (*data != '\0')
		return (free(line->ptr), -1);	
	return (1);
}
/* qprintf("data: '%s'\n", data); */

static int		parse_numants(char *data, t_line *line)
{
	line->type = numants;
	ft_parseuinteger(data, &line->v1);
	return (free(line->ptr), 1);
}

static int		parse_anthill_info(char *data, t_line *line)
{
	if (ft_strequ(data, "##end"))
	{
		line->type = endflag;
		return (free(line->ptr), 1);
	}
	else if (ft_strequ(data, "##start"))
	{
		line->type = startflag;
		return (free(line->ptr), 1);
	}
	else if (ft_strlen(data) == ft_strspn(data, "0123456789"))//no spaces affer numants
		return (parse_numants(data, line));
	line->name1 = data;
	ft_skiptype(&data, &li_is_namechar);
	ft_skiptype(&data, &ft_isblank);
	if (*data == '-')
		return (parse_connection(data, line));
	return (parse_room(data, line));
}
extern int i;
int				li_parse_next_line(t_line *line)
{
	char		*data;
	int			err;

	err = get_next_line(0, &line->ptr);
	data = line->ptr;
	if (err < 0)
		return (err);
	ft_skiptype(&data, &ft_isblank);	
	if (err == 0)
		return (free(line->ptr), err);
	if (data[0] == '#' && data[1] != '#')
	{
		line->type = comment;
		return (free(line->ptr), err);		
	}
	if (*data == '\0')
	{
		line->type = empty;
		return (free(line->ptr), 1);
	}
	return (parse_anthill_info(data, line));
}
