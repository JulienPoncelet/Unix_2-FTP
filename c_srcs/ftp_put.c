/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 16:52:02 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_put(t_client *client)
{
	int							fd;
	char						buf[2];
	int							ret;
	char						*cat;

	if ((fd = open(get_file(client->line), O_RDWR, 0644)) < 0)
		return (FT_ERROR);
	cat = "";
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[ret] = 0;
		cat = ft_strjoin(cat, buf);
	}
	ft_putnbrendl_fd(ft_strlen(cat), client->sd);
	send(client->sd, cat, ft_strlen(cat), 0);
	return (0);
}
