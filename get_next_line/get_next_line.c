/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:36:09 by tsannie           #+#    #+#             */
/*   Updated: 2021/01/04 16:02:45 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		searchreturn(char *src)
{
	int i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		write_line(char **line, char *stock, int i)
{
	*line = ft_substr(stock, 0, i);
	i++;
	ft_memmove(stock, stock + i, ft_strlen(stock + i) + 1);
	return (1);
}

char	*dup_free(char *stock, char **line)
{
	if (stock)
	{
		*line = ft_strdup(stock);
		free(stock);
		stock = NULL;
	}
	else
	{
		*line = ft_strdup("");
	}
	return (stock);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		buff[BUFFER_SIZE + 1];
	int			i;
	int			res;

	i = 0;
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) == -1)
		return (-1);
	i = searchreturn(stock);
	if (stock && (i != -1))
		return (write_line(line, stock, i));
	while (((res = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[res] = '\0';
		stock = ft_strjoin(stock, buff);
		i = searchreturn(stock);
		if (stock && (i != -1))
			return (write_line(line, stock, i));
	}
	stock = dup_free(stock, line);
	return (0);
}
