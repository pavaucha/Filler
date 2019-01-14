/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:31:45 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/02 10:38:02 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_filler	ft_complete_free(t_filler coord)
{
	int		i;

	i = 0;
	while (coord.map[i] != 0)
	{
		ft_strdel(&coord.map[i]);
		i++;
	}
	free(coord.map);
	coord.map = NULL;
	return (coord);
}

t_filler		ft_free_coord(t_filler coord)
{
	int		i;

	i = 0;
	coord = ft_complete_free(coord);
	while (i < coord.xmap)
	{
		free(coord.mpi[i]);
		coord.mpi[i] = NULL;
		i++;
	}
	free(coord.mpi);
	coord.mpi = NULL;
	i = 0;
	while (coord.piece[i] != 0)
	{
		ft_strdel(&coord.piece[i]);
		i++;
	}
	free(coord.piece);
	coord.piece = NULL;
	return (coord);
}
