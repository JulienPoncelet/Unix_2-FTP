/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:14:58 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 10:17:36 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int							main(int ac, char **av, char **env)
{
	t_serveur				*serveur;

	ac--;
	av++;
	if (check_input(ac) == FT_ERROR)
		return (EXIT_FAILURE);
	if (!(serveur = init_serveur(av, env)))
	{
		ft_error("serveur", "main.c", 23);
		return (EXIT_FAILURE);
	}
	loop(serveur);
	if (end_serveur(serveur) == FT_ERROR)
	{
		ft_error("serveur", "main.c", 28);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
