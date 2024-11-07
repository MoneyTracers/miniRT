/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_capital.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:07:59 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/07 14:14:44 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

  
#include <parse.h>

int parse_check_ambient(char *str)
{
	int	i;
	i = 0;

	if (!ft_strncmp(str, "A ", 2))
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
	if (str[i] != '\n' && str[i] != '\0')
		return (1);
	return (0);
}
int parse_check_camera(char *str)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "C ", 2))
		i++;
	else
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_iscoordinates(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isnormalvec(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isfloat(str, 0, &i))
		return (1);
	if (str[i] != '\n' && str[i] != '\0')
		return (1);
	return (0);
}
int parse_check_light(char *str)
{
	int	i;

	debugger("here3\n");
	i = 0;
	if (!ft_strncmp(str, "L ", 2))
		i++;
	else
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_iscoordinates(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_inrange_float(0.0, 1.0, str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isinrange_int(0, 180, str, &i))
		return (1);
	if (str[i] != '\n')
		return (1);
	return (0);
}

int	parse_check_correctness(t_parse *parse)
{
	debugger(YEL "%s:%d - %s\nparse_check_correctness\n\n" RESET, __FILE__, __LINE__, __FUNCTION__ );
	if (parse->type == ambient)
		return (parse_check_ambient(parse->str));
	else if (parse->type == camera)
		return (parse_check_camera(parse->str));
	else if (parse->type == light)
		return (parse_check_light(parse->str));
	else if (parse->type == sphere)
		return (parse_check_sphere(parse->str));
	else if (parse->type == plane)
		return (parse_check_plane(parse->str));
	else if (parse->type == cyl)
		return (parse_check_cyl(parse->str));
	else if (parse->type == unidentified)
		return (parse_check_unidentified(parse->str));
	return (1);
}
