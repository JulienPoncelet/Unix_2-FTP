/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 11:01:03 by jponcele         ###   ########.fr       */
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
		ft_putnbrendl_fd(LS_OPEN, sson);
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
	closedir(dd);
	return (0);
	(void)av;
}
