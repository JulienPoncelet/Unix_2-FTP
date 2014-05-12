/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 20:45:45 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 20:54:28 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

void						loop_client(t_client *client)
{
	int						type;
	char					*line;

	while (42)	
	{
		ft_putstr("$> ");
		type = getnexttype_c(0, &line);
		ft_putendl_fd(line, client->sd);
		if (type == QUIT)
			break ;
	}
}
