/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 09:42:36 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/13 10:09:31 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

void						send_pwd(int sson, char *pwd)
{
	ft_putendl_fd(pwd, sson);
}

char						*ft_getenv(char **env, char *name)
{
	int						i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(name, env[i], ft_strlen(name)))
			return (env[i] + ft_strlen(name));
		i++;
	}
	return (NULL);
}
