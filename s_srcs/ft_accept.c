/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 15:33:57 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 17:30:39 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int							ft_accept(int sd)
{
	int						cs;
	struct sockaddr_in		csin;
	unsigned int			clen;

	if ((cs = accept(sd, (struct sockaddr *)&csin, &clen)) == -1)
	{
		ft_error("serveur", "ft_accept.c", 21);
		return (FT_ERROR);
	}
	return (cs);
}
