/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnexttype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:29:42 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/12 18:35:56 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp.h>

int							getnexttype(int sson, char ***av)
{
	char					*line;
	char					**split;
	int						type;

	if (get_next_line(sson, &line) == -1)
		return (ft_error("serveur", "getnexttype.c", 20));
	printf("%s\n", line);
	split = ft_strsplit(line, " ");
	type = get_type(split[0]);
	*av = ++split;
	return (type);
}

int							get_type(char *cmd)
{
	int						i;
	static char				*type_cmd[TYPE_SIZE] = TYPE_CMD;
	static int				type_enum[TYPE_SIZE] = TYPE_ENUM;

	if (!cmd)
		return (NONE);
	i = 0;
	while (i < TYPE_SIZE)
	{
		if (ft_strequ(cmd, type_cmd[i]))
			return (type_enum[i]);
		i++;
	}
	return (WRONG);
}
