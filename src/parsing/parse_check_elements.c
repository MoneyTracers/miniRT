/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_check_elements.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 14:29:18 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/06 16:49:32 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

  
#include <parse.h>

int parse_check_sphere(char *str)
{
	int	i;
	debugger("here4\n");

	i = 0;
	if (!ft_strncmp(str, "sp ", 3))
		i += 2;
	else
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_iscoordinates(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isfloat(str, ' ', &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isrgb_inrange(0, 255, str, &i))
		return (1);
	if (str[i] != '\n')
		return (1);
	return (0);
}
int parse_check_plane(char *str)
{
	int	i;
	debugger("here5\n");

	i = 0;
	if (!ft_strncmp(str, "pl ", 3))
		i += 2;
	else
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_iscoordinates(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isnormalvec(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isrgb_inrange(0, 255, str, &i))
		return (1);
	if (str[i] != '\n')
		return (1);
	return (0);
}
int parse_check_cyl(char *str)
{
	int	i;
	debugger("here6\n");

	i = 0;
	if (!ft_strncmp(str, "cy ", 3))
		i += 2;
	else
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_iscoordinates(str, &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isnormalvec(str, &i))
		return (1);
	if (!parse_isfloat(str, ' ', &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isfloat(str, ' ', &i))
		return (1);
	i = parse_skipwhitespace(str, i);
	if (!parse_isrgb_inrange(0, 255, str, &i))
		return (1);
	if (str[i] != '\n')
		return (1);
	return (0);
}
int parse_check_unidentified(char *str)
{
	int	i;
	debugger("here7\n");

	i = 0;
	i = parse_skipwhitespace(str, i);
	if (str[i] != '\n')
		return (1);
	return (0);
}
