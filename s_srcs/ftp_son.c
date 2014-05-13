/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_son.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:07:17 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 16:56:36 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

void				ftp_son(int sson, char *pwd)
{
	int				type;
	char			**av;
	int				i;
	static int		type_enum[TYPE_SIZE] = TYPE_ENUM;
	static int		(*type_fun[TYPE_SIZE])(int, char **, char **) = TYPE_FUN;

	send_pwd(sson, pwd);
	while (42)
	{
		type = getnexttype(sson, &av);
		if (type == QUIT)
			break ;
		i = 0;
		while (i < TYPE_SIZE)
		{
			if (type_enum[i] == type)
				type_fun[i](sson, &pwd, av);
			i++;
		}
	}
	close(sson);
}
