/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 10:41:49 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_cd(t_client *client)
{
	char						*line;
	int							ret;
	static char					*e_cd[3] = E_CD;

	ft_putnbrendl_fd(client->lvl, client->sd);
	get_next_line(client->sd, &line);
	ret = ft_atoi(line);
	client->lvl = (ret == FT_ERROR) ? client->lvl : ret;
	get_next_line(client->sd, &line);
	ret = ft_atoi(line);
	if (!ret)
		client->pwd = line;
	else
	{
		ft_putstr(RED);
		ft_putstr("\nERROR: ");
		ft_putendl(e_cd[ret - 1]);
	}
	return (ret);
}
