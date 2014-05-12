/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 11:17:09 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 15:51:00 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								ft_bind(int sd, int port)
{
	struct sockaddr_in			sockin;

	sockin.sin_family = FAMILY;
	sockin.sin_port = HTONS(port);
	sockin.sin_addr.s_addr = INADDR_ANY;
	ft_bzero(&(sockin.sin_zero), 8);
	if (bind(sd, (struct sockaddr *)&sockin, sizeof(struct sockaddr_in)) == -1)
		return (ft_error("serveur", "ft_bind.c", 23));
	return (0);
}
