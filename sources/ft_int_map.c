/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:13:14 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/02 12:41:49 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

static int		ft_find_position(t_filler coord, int l, int m)
{
	int		i;
	int		j;
	int		k;
	int		tmp;

	i = -1;
	tmp = coord.xmap + coord.ymap;
	if (coord.map[l][m] == coord.c || coord.map[l][m] == (coord.c - 32))
		return (0);
	else if (coord.map[l][m] == coord.a || coord.map[l][m] == (coord.a - 32))
		return (-1);
	while (coord.map[++i] != 0)
	{
		j = -1;
		while (coord.map[i][++j] != '\0')
		{
			if (coord.map[i][j] == coord.a || coord.map[i][j] == (coord.a - 32))
			{
				k = ft_abs(i - l) + ft_abs(j - m);
				if (k < tmp)
					tmp = k;
			}
		}
	}
	return (tmp);
}

t_filler		ft_int_map(t_filler coord)
{
	int			i;
	int			j;

	i = 0;
	if ((coord.mpi = (int**)malloc(sizeof(int*) * (coord.xmap))) == NULL)
		return (coord);
	while (i < coord.xmap)
	{
		if ((coord.mpi[i] = (int*)malloc(sizeof(int) * coord.ymap)) == NULL)
			return (coord);
		i++;
	}
	i = 0;
	while (i < coord.xmap)
	{
		j = 0;
		while (j < coord.ymap)
		{
			coord.mpi[i][j] = ft_find_position(coord, i, j);
			j++;
		}
		i++;
	}
	return (coord);
}
