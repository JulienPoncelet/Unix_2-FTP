/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:14:58 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 20:52:15 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int							main(int ac, char **av)
{
	t_client				*client;

	ac--;
	av++;
	if (check_input(ac) == FT_ERROR)
		return (EXIT_FAILURE);
	if (!(client = init_client(av[0], ft_atoi(av[1]))))
	{
		ft_error("client", "main.c", 23);
		return (EXIT_FAILURE);	
	}
	loop_client(client);
	end_client(client);
	return (EXIT_SUCCESS);
}
