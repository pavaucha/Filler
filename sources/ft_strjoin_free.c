/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 10:45:58 by pavaucha          #+#    #+#             */
/*   Updated: 2018/10/02 10:46:13 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char		*ft_strjoin_free(char *str, char *dst)
{
	char	*new;
	int		i;

	if (str == NULL && dst == NULL)
		return (NULL);
	i = ft_strlen(str) + ft_strlen(dst) + 1;
	if ((new = ft_memalloc(i)) == NULL)
		return (NULL);
	new = ft_strcpy(new, str);
	new = ft_strcat(new, dst);
	ft_strdel(&str);
	ft_strdel(&dst);
	return (new);
}
