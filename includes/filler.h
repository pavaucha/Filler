/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:11:29 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/02 13:18:56 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BUFF_SIZE 2
# include "../libft/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>

typedef struct		s_filler
{
	int				zero;
	int				point;
	int				diffx;
	int				diffy;
	int				**mpi;
	char			c;
	char			a;
	char			**map;
	char			**piece;
	int				xmap;
	int				ymap;
	int				xpiece;
	int				ypiece;
	int				xa;
	int				ya;
	int				position;
}					t_filler;

char				*ft_strjoin_free(char *str, char *dst);
t_filler			ft_free_coord(t_filler coord);
t_filler			ft_int_map(t_filler coord);
t_filler			ft_parse(t_filler coord);
int					get_next_line(const int fd, char **line);
int					ft_put_piece(t_filler coord);

#endif
