/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 10:09:45 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/18 15:16:02 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int								c_ftp_pwd(t_client *client)
{
	char						**split;
	int							i;

	split = ft_strsplit(client->pwd, "/");
	i = 0;
	while (split[i])
	{
		if (ft_strequ(split[i], ".serveur"))
			break ;
		i++;
	}
	while (split[i])
	{
		ft_putchar('/');
		ft_putstr(split[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
