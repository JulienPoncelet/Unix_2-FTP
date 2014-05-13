/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 20:45:45 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 16:53:31 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

void						loop_client(t_client *client)
{
	int						type;
	char					*line;
	int						i;
	static int				type_enum[TYPE_SIZE] = TYPE_ENUM;
	static int				(*type_fun2[TYPE_SIZE])(t_client *) = TYPE_FUN2;

	get_next_line(client->sd, &(client->pwd));
	while (42)
	{
		print_prompt(client);
		type = getnexttype_c(0, &line);
		ft_putendl_fd(line, client->sd);
		client->line = ft_strdup(line);
		if (type == QUIT)
			break ;
		i = 0;
		while (i < TYPE_SIZE)
		{
			if (type == type_enum[i])
				launch(type_fun2[i], client);
			i++;
		}
	}
}

void						print_prompt(t_client *client)
{
	ft_putstr(BLUE);
	ft_putstr(client->addr);
	ft_putstr(WHITE);
	ft_putstr(":");
	ft_putstr(YELLOW);
	ft_putnbr(client->port);
	ft_putstr(WHITE);
	ft_putstr(" > ");
}

void						launch(int (*f)(t_client *), t_client *client)
{
	int						error;

	error = f(client);
	if (!error)
	{
		ft_putstr(GREEN);
		ft_putendl("\n-SUCCESS\n");
	}
	else
	{
		ft_putstr(RED);
		ft_putendl("\n-ERROR\n");
	}
}
