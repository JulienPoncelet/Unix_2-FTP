/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 20:05:42 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 20:09:13 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int							check_input(int ac)
{
	if (ac == 2)
		return (0);
	ft_putendl(C_USAGE);
	return (FT_ERROR);
}