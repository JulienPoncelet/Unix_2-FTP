/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 20:14:29 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/18 15:48:25 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# include <error.h>
# include <libft.h>
# include <get_next_line.h>
# include <netdb.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>

# define WHITE			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[36m"

# define S_USAGE		"usage: ./serveur <port = 1024>"
# define C_USAGE		"usage: ./client <addr> <port>"

# define DOMAIN			PF_INET
# define TYPE			SOCK_STREAM
# define FAMILY			AF_INET
# define BACKLOG		42

enum					e_type
{
	LS, CD, GET, PUT, PWD, MKDIR, QUIT, WRONG, NONE
};

# define TYPE_ENUM		{LS, CD, GET, PUT, PWD, MKDIR, QUIT}
# define TYPE_CMD		{"ls", "cd", "get", "put", "pwd", "mkdir", "quit"}
# define TYPE_FUN		{ftp_ls, ftp_cd, ftp_get, ftp_put, ftp_pwd, ftp_mkdir}
# define TF	{c_ftp_ls, c_ftp_cd, c_ftp_get, c_ftp_put, c_ftp_pwd, c_ftp_mkdir}
# define TYPE_SIZE		7

typedef struct			s_serveur
{
	int					sd;
	int					port;
	char				*pwd;
}						t_serveur;

typedef struct			s_client
{
	int					sd;
	char				*addr;
	int					port;
	char				*pwd;
	char				*line;
	int					lvl;
}						t_client;

/*
**						check_input.c
*/

int						check_input(int ac);

/*
**						t_serveur.c
*/

t_serveur				*init_serveur(char **av, char **env);
t_serveur				*init_serveur2(t_serveur *serveur, char **env);
void					create_dir(void);
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

void					ftp_son(int sson, char *pwd);

/*
**						send_pwd.c
*/

void					send_pwd(int sson, char *pwd);
char					*ft_getenv(char **env, char *name);

/*
**						getnexttype.c
*/

int						getnexttype(int sson, char ***av);
int						getnexttype_c(int sson, char **av);
int						get_type(char *cmd);

/*
**						ftp_cmd
*/

int						ftp_ls(int sson, char **pwd, char **av);
int						ftp_cd(int sson, char **pwd, char **av);
char					*parse_pwd(char *src, char *dst, int *lvl);
char					*delete_last(char *pwd);
int						ftp_get(int sson, char **pwd, char **av);
char					*get_file(char *line);
int						ftp_put(int sson, char **pwd, char **av);
int						ftp_pwd(int sson, char **pwd, char **av);
int						ftp_mkdir(int sson, char **pwd, char **av);

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
void					print_prompt(t_client *client);
void					launch(int (*f)(t_client *), t_client *client);
void					put_wrong(void);

/*
**						c_ftp_cmd
*/

int						c_ftp_ls(t_client *client);
int						c_ftp_cd(t_client *client);
int						c_ftp_get(t_client *client);
int						put_get_error(int code);
int						c_ftp_put(t_client *client);
int						put_error_put(int code);
int						c_ftp_pwd(t_client *client);
int						c_ftp_mkdir(t_client *client);

#endif
