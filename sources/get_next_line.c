/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:30:05 by pavaucha          #+#    #+#             */
/*   Updated: 2018/09/22 18:28:16 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	*ft_read(char *str, int fd)
{
	char	*temp;
	char	*buf;
	int		ret;

	if ((buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = str;
		if ((str = ft_strjoin(str, buf)) == NULL)
			return (0);
		ft_strdel(&temp);
		if ((ft_strchr(buf, '\n')) != NULL)
			break ;
	}
	ft_strdel(&buf);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			i;

	i = 0;
	if (line == NULL || BUFF_SIZE < 1 || read(fd, NULL, 0) == -1 ||
			fd > OPEN_MAX)
		return (-1);
	if (str[fd] == NULL)
		if ((str[fd] = ft_strnew(1)) == NULL)
			return (-1);
	if ((str[fd] = ft_read(str[fd], fd)) == NULL)
		return (-1);
	if (str[fd][0] != '\0')
	{
		while (str[fd][i] != '\n' && str[fd][i] != '\0')
			i++;
		if (((*line) = ft_strsub(str[fd], 0, i)) == NULL)
			return (-1);
		if (str[fd][i] == '\0')
			i--;
		str[fd] = ft_strncpy(str[fd], &str[fd][i + 1], ft_strlen(str[fd]));
		return (1);
	}
	return (0);
}
