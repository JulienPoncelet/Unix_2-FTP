/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:25:22 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 14:15:16 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_cd(t_client *client)
{
	char						*line;
	int							ret;

	get_next_line(client->sd, &line);
	ret = ft_atoi(line);
	if (ret != FT_ERROR)
		client->pwd = line;
	return ((ret == FT_ERROR) ? ret : 0);
}
