/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 16:32:22 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ftp_get(int sson, char **pwd, char **av)
{
	int							fd;
	char						buf[2];
	int							ret;
	char						*cat;

	if (!av[0] || !pwd)
	{
		ft_putnbrendl_fd(FT_ERROR, sson);
		return (FT_ERROR);
	}
	if ((fd = open(av[0], O_RDWR, 0644)) < 0)
	{
		ft_putnbrendl_fd(FT_ERROR, sson);
		return (FT_ERROR);
	}
	ft_putnbrendl_fd(0, sson);
	cat = "";
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[ret] = 0;
		cat = ft_strjoin(cat, buf);
	}
	ft_putnbrendl_fd(ft_strlen(cat), sson);
	send(sson, cat, ft_strlen(cat), 0);
	return (0);
}
