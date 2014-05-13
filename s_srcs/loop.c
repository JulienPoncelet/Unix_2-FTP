/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 15:30:52 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 10:48:15 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

void						loop(t_serveur *serveur)
{
	int						end;
	int						sson;
	pid_t					father;

	end = 0;
	while (!end)
	{
		if ((sson = ft_accept(serveur->sd)) == FT_ERROR)
			ft_error("serveur", "loop.c", 23);
		else
		{
			if ((father = fork()) == -1)
			{
				ft_error("serveur", "loop.c", 28);
				return ;
			}
			if (!father)
				ftp_son(sson, serveur->pwd);
		}
	}
}
