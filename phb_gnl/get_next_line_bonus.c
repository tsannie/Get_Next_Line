/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:03:31 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/25 19:46:14 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char				*next_line(char *save, char **line, int r)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (i < ft_strlen(save))
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else if (r == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

char				*save_line(char *buffer, char *save)
{
	char			*tmp;

	if (!save)
		save = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	return (save);
}

int					fill_next(int r, int fd, char **line, char **save)
{
	if (r <= 0 && !save[fd])
	{
		*line = ft_strdup("");
		return (r);
	}
	save[fd] = next_line(save[fd], line, r);
	if (r <= 0 && !save[fd])
		return (r);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*save[4096];
	int				r;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if ((r = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (-1);
	if (r > 0)
	{
		buffer[r] = '\0';
		save[fd] = save_line(buffer, save[fd]);
		return (get_next_line(fd, line));
	}
	return (fill_next(r, fd, line, save));
}
