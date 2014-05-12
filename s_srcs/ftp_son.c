/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_son.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:07:17 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 18:35:56 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

void							ftp_son(int sson)
{
	int							type;
	char						**av;
	int							i;
	int							type_enum[TYPE_SIZE] = TYPE_ENUM;
	void						(*type_fun[TYPE_SIZE])(int) = TYPE_FUN;

	while (42)
	{
		type = getnexttype(sson, &av);
		if (type == QUIT)
			break ;
		i = 0;
		while (i < TYPE_SIZE)
		{
			if (type_enum[i] == type)
				type_fun[i](type);
			i++;
		}
	}
	close(sson);
}
