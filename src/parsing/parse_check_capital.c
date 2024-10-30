/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_capital.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:07:59 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/30 14:28:32 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

int parse_check_ambient(char *str)
{
	return (0);
}
int parse_check_camera(char *str)
{
	return (0);
}
int parse_check_light(char *str)
{
	return (0);
}

int	parse_check_correctness(char *str, int type)
{
	if (type == ambient)
		return (parse_check_ambient(str));
	else if (type == camera)
		return (parse_check_camera(str));
	else if (type == light)
		return (parse_check_light(str));
	else if (type == sphere)
		return (parse_check_sphere(str));
	else if (type == plane)
		return (parse_check_plane(str));
	else if (type == cyl)
		return (parse_check_cyl(str));
	else if (type == unidentified)
		return (parse_check_unidentified(str));
}

