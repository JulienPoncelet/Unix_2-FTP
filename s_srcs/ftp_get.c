/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 12:21:00 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ftp_get(int sson, char **pwd, char **av)
{
	int							fd;
	char						*file;
	int							len;

	if (!av[0] || !pwd)
	{
		ft_putnbrendl_fd(GET_ARG, sson);
		return (FT_ERROR);
	}
	if ((fd = open(av[0], O_RDWR, 0644)) < 0)
	{
		ft_putnbrendl_fd(GET_OPEN, sson);
		return (FT_ERROR);
	}
	ft_putnbrendl_fd(0, sson);
	len = ft_filelen(fd);
	fd = open(av[0], O_RDWR, 0644);
	ft_putnbrendl_fd(len, sson);
	file = (char *)mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	send(sson, file, len, 0);
	return (0);
}
