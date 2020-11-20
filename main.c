/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:36:17 by tsannie           #+#    #+#             */
/*   Updated: 2020/11/19 15:02:01 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	**line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	line = malloc(sizeof(char**) * 10);
	(void)argc;

	printf("%d\n", get_next_line(fd, line));
	printf("----------------------------------\nResultat:\n");
	printf("%s\n",*line);
}
