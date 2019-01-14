/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:39:10 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/02 13:20:14 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_filler	ft_valide_pos(t_filler coord, int k, int l)
{
	if (coord.zero == 1 && (coord.point < coord.position || coord.position < 0))
	{
		coord.xa = k - coord.diffx;
		coord.ya = l - coord.diffy;
		coord.position = coord.point;
	}
	return (coord);
}

static t_filler	ft_test_piece(t_filler coord, int k, int l)
{
	int		i;
	int		j;

	i = -1;
	while (++i < coord.xpiece - coord.diffx)
	{
		j = -1;
		while (++j < coord.ypiece - coord.diffy)
		{
			if (coord.piece[i + coord.diffx][j + coord.diffy] == '*'
					&& (i + k) < coord.xmap && (j + l) < coord.ymap)
			{
				if (coord.mpi[k + i][l + j] == 0)
					coord.zero++;
				else if (coord.mpi[k + i][l + j] > 0)
					coord.point += coord.mpi[k + i][l + j];
				else if (coord.mpi[k + i][l + j] == -1)
					return (coord);
			}
			else if (coord.piece[i + coord.diffx][j + coord.diffy] != '.')
				return (coord);
		}
	}
	coord = ft_valide_pos(coord, k, l);
	return (coord);
}

static t_filler	ft_test_poser(t_filler coord)
{
	int		j;
	int		i;

	i = 0;
	coord.position = -1;
	while (i < coord.xmap)
	{
		j = 0;
		while (j < coord.ymap)
		{
			coord.zero = 0;
			coord.point = 0;
			coord = ft_test_piece(coord, i, j);
			j++;
		}
		i++;
	}
	return (coord);
}

int				ft_put_piece(t_filler coord)
{
	coord.xa = -100;
	coord.ya = -100;
	coord = ft_test_poser(coord);
	if (coord.xa == -100 && coord.ya == -100)
		return (0);
	ft_printf("%i %i\n", coord.xa, coord.ya);
	return (1);
}
