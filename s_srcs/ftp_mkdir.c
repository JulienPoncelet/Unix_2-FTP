/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_mkdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 15:18:23 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/18 15:44:10 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ftp_mkdir(int sson, char **pwd, char **av)
{
	if (!av[0])
	{
		ft_putnbrendl_fd(MKDIR_ARG, sson);
		return (FT_ERROR);
	}
	if ((mkdir(av[0], 0755)) == -1)
	{
		ft_putnbrendl_fd(MKDIR_EXIST, sson);
		return (FT_ERROR);
	}
	ft_putnbrendl_fd(0, sson);
	return (0);
	(void)pwd;
}
