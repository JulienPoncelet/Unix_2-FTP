/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:14:29 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 11:50:40 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

#include <stdio.h>

# include <libft.h>
# include <netdb.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>

# define S_USAGE		"usage: ./serveur <port = 1024>"

# define DOMAIN			PF_INET
# define TYPE			SOCK_STREAM
# define FAMILY			AF_INET

typedef struct			s_serveur
{
	int					sd;
	int					port;
}						t_serveur;

/*
**						check_input.c
*/

int						check_input(int ac);

/*
**						t_serveur.c
*/

t_serveur				*init_serveur(char **av);
int						end_serveur(t_serveur *serveur);

/*
**						ft_socket.c
*/

int						ft_socket(void);

/*
**						ft_bind.c
*/

int						ft_bind(int sd, int port);

#endif /* !FTP_H */

