/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_socket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 10:44:31 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 11:30:30 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int							ft_socket(void)
{
	struct protoent			*proto;
	int						sd;

	proto = getprotobyname("tcp");
	if (!proto)
		return (ft_error("serveur", "ft_socket.c", 20));
	sd = socket(DOMAIN, TYPE, proto->p_proto);
	if (sd == -1)
		return (ft_error("serveur", "ft_socket.c", 23));
	return (sd);
}
