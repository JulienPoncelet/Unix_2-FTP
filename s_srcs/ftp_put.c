/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 16:52:04 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ftp_put(int sson, char **pwd, char **av)
{
	char						*line;
	char						*file;
	int							fd;
	char						*cat;
	int							len;

	file = av[0];
	if ((fd = open(ft_strjoin(file, "_put"), O_RDWR | O_CREAT, 0644)) < 0)
		return (FT_ERROR);
	get_next_line(sson, &line);
	len = ft_atoi(line);
	cat = (char *)malloc(sizeof(char) * (len + 1));
	recv(sson, cat, len, 0);
	cat[len] = 0;
	ft_putstr_fd(cat, fd);
	return (0);
	(void)pwd;
}

char							*get_file(char *line)
{
	char						**split;

	split = ft_strsplit(line, " ");
	return (split[1]);
}
