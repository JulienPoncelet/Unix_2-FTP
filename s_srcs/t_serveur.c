/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_serveur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 10:42:45 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/18 15:40:09 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

t_serveur						*init_serveur(char **av, char **env)
{
	t_serveur					*serveur;

	if (!(serveur = (t_serveur *)malloc(sizeof(t_serveur))))
	{
		ft_error("serveur", "t_serveur.c", 19);
		return (NULL);
	}
	if ((serveur->sd = ft_socket()) == FT_ERROR)
	{
		ft_error("serveur", "t_serveur.c", 24);
		return (NULL);
	}
	serveur->port = (av[0]) ? ft_atoi(av[0]) : 1024;
	return (init_serveur2(serveur, env));
}

t_serveur						*init_serveur2(t_serveur *serveur, char **env)
{
	if (ft_bind(serveur->sd, serveur->port) == FT_ERROR)
	{
		ft_error("serveur", "t_serveur.c", 35);
		return (NULL);
	}
	if (ft_listen(serveur->sd) == FT_ERROR)
	{
		ft_error("serveur", "t_serveur.c", 40);
		return (NULL);
	}
	mkdir(".serveur", 0755);
	chdir(".serveur");
	if (!(serveur->pwd = ft_strdup(ft_getenv(env, "PWD="))))
	{
		ft_error("serveur", "t_serveur.c", 46);
		return (NULL);
	}
	serveur->pwd = ft_strjoin(serveur->pwd, "/.serveur");
	return (serveur);
}

int								end_serveur(t_serveur *serveur)
{
	if (close(serveur->sd) == -1)
		ft_error("serveur", "t_serveur.c", 40);
	free(serveur->pwd);
	free(serveur);
	return (0);
}
