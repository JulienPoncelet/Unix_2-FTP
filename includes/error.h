/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 11:47:48 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/14 12:02:02 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum					e_error_cd
{
	CD_ARG = 1, CD_PATH = 2, CD_LIM = 3
};

# define E_CD_ARG		"cd: need 1 argument, 0 given."
# define E_CD_PATH		"cd: no such file or directory."
# define E_CD_LIM		"cd: can't  descend to a lower level directory."
# define E_CD			{E_CD_ARG, E_CD_PATH, E_CD_LIM}

enum					e_error_get
{
	GET_ARG = 1, GET_OPEN = 2, GET_OPEN_GET = 3
};

# define E_GET_ARG		"get: need 1 argument, 0 given."
# define E_GET_OPEN		"get: no such file."
# define E_GET			{E_GET_ARG, E_GET_OPEN}

enum					e_error_ls
{
	LS_OPEN = -1
};

# define E_LS_OPEN		"ls: open fail on the current directory."

enum					e_error_put
{
	PUT_ARG = 1, PUT_OPEN = 2, PUT_OPEN_PUT = 3
};

# define E_PUT_ARG		"put: need 1 argument, 0 given."
# define E_PUT_OPEN		"put: no such file."
# define E_PUT			{E_PUT_ARG, E_PUT_OPEN}

#endif
