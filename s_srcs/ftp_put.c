/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 12:32:43 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ftp_put(int sson, char **pwd, char **av)
{
	char						*line;
	char						*file;
	int							fd;
	char						*file_recv;
	int							len;

	if (!av[0] || !pwd)
	{
		ft_putnbrendl_fd(PUT_ARG, sson);
		return (FT_ERROR);
	}
	file = av[0];
	if ((fd = open(ft_strjoin(file, "_put"), O_RDWR | O_CREAT, 0644)) < 0)
	{
		ft_putnbrendl_fd(PUT_OPEN_PUT, sson);
		return (FT_ERROR);
	}
	ft_putnbrendl_fd(0, sson);
	get_next_line(sson, &line);
	if ((len = ft_atoi(line)) == -1)
		return (FT_ERROR);
	file_recv = (char *)malloc(sizeof(char) * (len + 1));
	recv(sson, file_recv, len, 0);
	write(fd, file_recv, len);
	return (0);
}

char							*get_file(char *line)
{
	char						**split;

	split = ft_strsplit(line, " ");
	return (split[1]);
}
