/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 13:36:53 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_put(t_client *client)
{
	char						*line;
	int							fd;
	int							ret;
	char						*file;
	int							len;

	get_next_line(client->sd, &line);
	ret = ft_atoi(line);
	if (ret)
		return (put_error_put(ret));
	if ((fd = open(get_file(client->line), O_RDWR, 0644)) < 0)
	{
		ft_putnbrendl_fd(-1, client->sd);
		return (put_error_put(PUT_OPEN));
	}
	len = ft_filelen(fd);
	fd = open(get_file(client->line), O_RDWR, 0644);
	file = (char *)mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	ft_putnbrendl_fd(len, client->sd);
	send(client->sd, file, len, 0);
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
