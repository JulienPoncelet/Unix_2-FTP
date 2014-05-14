/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 10:41:47 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ftp_cd(int sson, char **pwd, char **av)
{
	char						*save_pwd;
	char						*line;
	int							lvl;

	get_next_line(sson, &line);
	lvl = ft_atoi(line);
	if (!av[0])
	{
		ft_putnbrendl_fd(lvl, sson);
		ft_putnbrendl_fd(CD_ARG, sson);
		return (FT_ERROR);
	}
	save_pwd = ft_strdup(*pwd);
	*pwd = parse_pwd(*pwd, av[0], &lvl);
	if ((chdir(*pwd)) == -1 || lvl < 0)
	{
		ft_putnbrendl_fd(FT_ERROR, sson);
		ft_putnbrendl_fd((lvl < 0) ? CD_LIM : CD_PATH, sson);
		*pwd = save_pwd;
		return (FT_ERROR);
	}
	ft_putnbrendl_fd(lvl, sson);
	ft_putendl_fd(*pwd, sson);
	return (0);
}

char							*parse_pwd(char *src, char *dst, int *lvl)
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
			{
				src = delete_last(src);
				*lvl = *lvl - 1;
			}
			else
			{
				src = ft_strjoin(src, split[i]);
				*lvl = *lvl + 1;
			}
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
