/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:46:28 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/02 12:47:10 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char		*ft_get_dst(char *str, int j)
{
	int		i;
	char	*dst;

	i = 0;
	while (str[i])
		i++;
	dst = ft_strnew(i - j + 1);
	dst = ft_strcpy(dst, str + j);
	dst[i - j] = '\n';
	return (dst);
}

static t_filler	ft_get_x_y(t_filler coord, char *str, int j)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (j == 1)
			{
				coord.xmap = ft_atoi(str + i);
				while (str[i] != ' ')
					i++;
				coord.ymap = ft_atoi(str + i);
			}
			if (j == 2)
			{
				coord.xpiece = ft_atoi(str + i);
				while (str[i] != ' ')
					i++;
				coord.ypiece = ft_atoi(str + i);
			}
			break ;
		}
	}
	return (coord);
}

static t_filler	ft_piece(char *str, t_filler coord)
{
	int		i;
	char	*dst;

	dst = ft_strnew(0);
	i = 0;
	coord = ft_get_x_y(coord, str, 2);
	ft_strdel(&str);
	while (i < coord.xpiece)
	{
		get_next_line(0, &str);
		dst = ft_strjoin_free(dst, ft_get_dst(str, 0));
		ft_strdel(&str);
		i++;
	}
	coord.piece = ft_strsplit(dst, '\n');
	ft_strdel(&dst);
	return (coord);
}

static t_filler	ft_get_maps(t_filler coord)
{
	char	*dst;
	char	*str;

	dst = ft_strnew(0);
	while (get_next_line(0, &str))
	{
		if (str[0] != 'P')
		{
			dst = ft_strjoin_free(dst, ft_get_dst(str, 4));
			ft_strdel(&str);
		}
		else if (str[0] == 'P')
		{
			coord = ft_piece(str, coord);
			break ;
		}
	}
	coord.map = ft_strsplit(dst, '\n');
	ft_strdel(&dst);
	return (coord);
}

t_filler		ft_parse(t_filler coord)
{
	char		*str;

	get_next_line(0, &str);
	while (str[0] != 'P')
	{
		ft_strdel(&str);
		get_next_line(0, &str);
	}
	if (coord.xmap == 0 && coord.ymap == 0)
		coord = ft_get_x_y(coord, str, 1);
	ft_strdel(&str);
	get_next_line(0, &str);
	ft_strdel(&str);
	coord = ft_get_maps(coord);
	return (coord);
}
