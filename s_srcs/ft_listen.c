/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:55:06 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 15:33:53 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int							ft_listen(int sd)
{
	if (listen(sd, BACKLOG) == -1)
		return (ft_error("serveur", "ft_listen.c", 17));
	return (0);
}
