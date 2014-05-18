/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_mkdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 15:19:08 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/18 15:44:12 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_mkdir(t_client *client)
{
	char						*line;
	int							ret;
	static char					*e_mkdir[2] = E_MKDIR;

	get_next_line(client->sd, &line);
	ret = ft_atoi(line);
	if (ret)
	{
		ft_putstr(RED);
		ft_putstr("\nERROR: ");
		ft_putendl(e_mkdir[ret - 1]);
	}
	return (ret);
}
