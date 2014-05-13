/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 16:44:26 by jponcele         ###   ########.fr       */
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
	if (ft_atoi(line) == FT_ERROR)
		return (FT_ERROR);
	file = get_file(client->line);
	if ((fd = open(ft_strjoin(file, "_cpy"), O_RDWR | O_CREAT, 0644)) < 0)
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
