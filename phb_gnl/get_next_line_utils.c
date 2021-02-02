/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <phbarrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:04:38 by phbarrad          #+#    #+#             */
/*   Updated: 2020/11/26 16:53:33 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			j;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*tab;
	unsigned int	len;
	unsigned int	i;

	i = -1;
	len = -1;
	if (!s1 || !s2)
		return (NULL);
	if (!(tab = malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[++len])
		tab[i + len] = s2[len];
	tab[i + len] = '\0';
	return (tab);
}

char				*ft_strdup(const char *s1)
{
	int				len;
	char			*str;
	int				i;

	i = -1;
	len = 0;
	while (s1[len])
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
