/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 13:43:29 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ftp_ls(int sson, char **pwd, char **av)
{
	DIR							*dd;
	struct dirent				*file;
	char						*buf;

	if (!(dd = opendir(*pwd)))
	{
		ft_error("serveur", "ftp_ls.c", 20);
		ft_putnbrendl_fd(FT_ERROR, sson);
		return (FT_ERROR);
	}
	buf = "";
	while ((file = readdir(dd)))
	{
		if (file->d_name[0] != '.')
		{
			buf = ft_strjoin(buf, file->d_name);
			buf = ft_strjoin(buf, "\n");
		}
	}
	ft_putnbrendl_fd(ft_strlen(buf), sson);
	send(sson, buf, ft_strlen(buf) + 1, 0);
	return (0);
	(void)av;
}
