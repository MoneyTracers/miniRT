/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_capital.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:07:59 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/31 18:16:39 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

int parse_check_ambient(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 'A' && str[i + 1] == ' ')
		i++;
	else
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_inrange_float(0.0, 1.0, str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isrgb_inrange(0, 255, str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (str[i] != '\n');
		return (1);
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

