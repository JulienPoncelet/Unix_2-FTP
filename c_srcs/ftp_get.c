/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 12:03:11 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_get(t_client *client)
{
	char						*line;
	char						*file;
	int							fd;
	char						*cat;
	int							len;

	get_next_line(client->sd, &line);
	if (ft_atoi(line))
		return (put_get_error(ft_atoi(line)));
	file = get_file(client->line);
	if ((fd = open(ft_strjoin(file, "_get"), O_RDWR | O_CREAT, 0644)) < 0)
		return (FT_ERROR);
	get_next_line(client->sd, &line);
	len = ft_atoi(line);
	cat = (char *)malloc(sizeof(char) * (len + 1));
	recv(client->sd, cat, len, 0);
	cat[len] = 0;
	ft_putstr_fd(cat, fd);
	return (0);
}

char							*get_file(char *line)
{
	char						**split;

	split = ft_strsplit(line, " ");
	return (split[1]);
}

int								put_get_error(int code)
{
	static char					*e_get[2] = E_GET;

	ft_putstr(RED);
	ft_putstr("\nERROR: ");
	ft_putendl(e_get[code - 1]);
	return (code);
}
