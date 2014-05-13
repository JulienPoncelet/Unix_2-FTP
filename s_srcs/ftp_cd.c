/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 13:52:33 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ftp_cd(int sson, char **pwd, char **av)
{
	char						*save_pwd;

	if (!av[0])
	{
		ft_putnbrendl_fd(FT_ERROR, sson);
		return (FT_ERROR);
	}
	save_pwd = ft_strdup(*pwd);
	*pwd = parse_pwd(*pwd, av[0]);
	if ((chdir(*pwd)) == -1)
	{
		ft_putnbrendl_fd(FT_ERROR, sson);
		*pwd = save_pwd;
		return (ft_error("serveur", "ftp_cd.c", 20));
	}
	ft_putendl_fd(*pwd, sson);
	return (0);
}

char							*parse_pwd(char *src, char *dst)
{
	char						**split;
	int							i;

	split = ft_strsplit(dst, "/");
	i = 0;
	while (split[i])
	{
		if (!ft_strequ(split[i], "."))
		{
			src = ft_strjoin(src, "/");
			if (ft_strequ(split[i], ".."))
				src = delete_last(src);
			else
				src = ft_strjoin(src, split[i]);
		}
		i++;
	}
	return (src);
}

char							*delete_last(char *pwd)
{
	int							i;

	i = ft_strlen(pwd) - 2;
	while (pwd[i])
	{
		if (pwd[i] == '/')
			break ;
		i--;
	}
	while (pwd[i])
	{
		pwd[i] = 0;
		i++;
	}
	return (pwd);
}
