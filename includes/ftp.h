/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:14:29 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 20:52:42 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

#include <stdio.h>

# include <libft.h>
# include <get_next_line.h>
# include <netdb.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define S_USAGE		"usage: ./serveur <port = 1024>"
# define C_USAGE		"usage: ./client <addr> <port>"

# define DOMAIN			PF_INET
# define TYPE			SOCK_STREAM
# define FAMILY			AF_INET
# define BACKLOG		42

enum					e_type
{
	LS, CD, GET, PUT, PWD, QUIT, WRONG, NONE
};

# define TYPE_ENUM		{LS, CD, GET, PUT, PWD, QUIT}
# define TYPE_CMD		{"ls", "cd", "get", "put", "pwd", "quit"}
# define TYPE_FUN		{ftp_ls, ftp_cd, ftp_get, ftp_put, ftp_pwd}
# define TYPE_SIZE		6

typedef struct			s_serveur
{
	int					sd;
	int					port;
}						t_serveur;

typedef struct			s_client
{
	int					sd;
}						t_client;

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

/*
**						ft_listen.c
*/

int						ft_listen(int sd);

/*
**						ft_accept.c
*/

int						ft_accept(int sd);

/*
**						loop.c
*/


void					loop(t_serveur *serveur);

/*
**						ftp_son.c
*/

void					ftp_son(int sson);

/*
**						getnexttype.c
*/

int						getnexttype(int sson, char ***av);
int						getnexttype_c(int sson, char **av);
int						get_type(char *cmd);

/*
**						ftp_fun1.c
*/

void					ftp_ls(int type);
void					ftp_cd(int type);
void					ftp_get(int type);
void					ftp_put(int type);
void					ftp_pwd(int type);

/*
**						t_client.c
*/

t_client				*init_client(char *addr, int port);
void					end_client(t_client *client);

/*
**						ft_connect.c
*/

int						ft_connect(int sd, char *addr, int port);

/*
**						loop.c
*/

void					loop_client(t_client *client);

#endif /* !FTP_H */
