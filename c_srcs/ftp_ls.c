/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 12:38:55 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_ls(t_client *client)
{
	char						*line;
	int							len;
	char						*buf;

	get_next_line(client->sd, &line);
	len = ft_atoi(line);
	if (len == FT_ERROR)
		return (FT_ERROR);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	recv(client->sd, buf, len + 1, 0);
	ft_putstr(buf);
	free(buf);
	return (0);
}
