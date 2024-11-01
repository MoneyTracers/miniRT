/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_capital.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:07:59 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/01 11:06:43 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

int parse_check_ambient(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "A ", 2))
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
	int	i;

	i = 0;
	if (ft_strncmp(str, "C ", 2))
		i++;
	else
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_is_coordinates(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isnormalvec(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isrgb_inrange(0, 255, str, &i))
		return (1);
	if (str[i] != '\n');
		return (1);
	return (0);
}
int parse_check_light(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "L ", 2))
		i++;
	else
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_is_coordinates(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_inrange_float(0.0, 1.0, str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isinrange_int(0, 180, str, &i))
		return (1);
	if (str[i] != '\n');
		return (1);
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

