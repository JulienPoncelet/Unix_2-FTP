/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 12:03:19 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_put(t_client *client)
{
	char						*line;
	int							fd;
	char						buf[2];
	int							ret;
	char						*cat;

	get_next_line(client->sd, &line);
	ret = ft_atoi(line);
	if (ret)
		return (put_error_put(ret));
	if ((fd = open(get_file(client->line), O_RDWR, 0644)) < 0)
		return (put_error_put(PUT_OPEN));
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

int								put_error_put(int code)
{
	static char					*e_put[3] = E_PUT;

	ft_putstr(RED);
	ft_putstr("\nERROR: ");
	ft_putendl(e_put[code - 1]);
	return (code);
}
