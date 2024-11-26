/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/29 16:20:17 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/26 14:02:43 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void set_error(t_world *world, int exit_code, int err_msg, void *mem)
{
	world->exit_code = exit_code;
	world->err = err_msg;
	free(mem);
	mem = NULL;
	return ;
}

void exit_err(char *err, int ec)
{
	perror(err);
	exit (ec);
}