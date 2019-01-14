/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:19:58 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/02 12:43:23 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static t_filler		ft_diff_piece(t_filler coord)
{
	int		i;
	int		j;

	i = 0;
	coord.diffx = 100;
	coord.diffy = 100;
	while (i < coord.xpiece)
	{
		j = 0;
		while (j < coord.ypiece)
		{
			if (coord.piece[i][j] == '*')
			{
				if (i < coord.diffx)
					coord.diffx = i;
				if (j < coord.diffy)
					coord.diffy = j;
			}
			j++;
		}
		i++;
	}
	return (coord);
}

static t_filler		rdy_player_one(t_filler coord)
{
	char		*str;
	int			i;

	i = 0;
	while (get_next_line(0, &str))
	{
		if (str[0] == '$')
			break ;
		ft_strdel(&str);
	}
	while (str[i] != 'p')
		i++;
	i = str[i + 1] - '0';
	if (i == 1)
	{
		coord.c = 'O';
		coord.a = 'X';
	}
	else
	{
		coord.c = 'X';
		coord.a = 'O';
	}
	ft_strdel(&str);
	return (coord);
}

int					main(void)
{
	t_filler	coord;

	coord.xmap = 0;
	coord.ymap = 0;
	coord = rdy_player_one(coord);
	while (1)
	{
		coord = ft_parse(coord);
		coord = ft_int_map(coord);
		coord.diffx = 0;
		coord.diffy = 0;
		coord = ft_diff_piece(coord);
		if (ft_put_piece(coord) == 0)
		{
			coord = ft_free_coord(coord);
			break ;
		}
		coord = ft_free_coord(coord);
	}
	ft_printf("0 0\n");
	return (0);
}
