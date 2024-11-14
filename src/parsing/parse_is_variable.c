/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_is_variable.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/13 12:13:24 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <minirt.h>

int	parse_isint(char *num, int *i)
{
	int	start;

	start = *i;
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (num[*i] != ' ' && num[*i] != '\n')
		return (0);
	if (ft_strncmp(num, "2147483647", *i - start) < 0)
		return (0);
	return (1);
}

int	parse_isfloat(char *num, char end_delim, int *i)
{
	if (num[*i] == '-')
		*i += 1;
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (end_delim && num[*i] == end_delim)
		return (1);
	else if (num[*i] == ' ' || num[*i] == '\n')
		return (1);
	if (num[*i] != '.')
		return (0);
	*i += 1;
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (end_delim && num[*i] == end_delim)
		return (1);
	else if (num[*i] == ' ' || num[*i] == '\n')
		return (1);
	return (0);
}

int	parse_iscoordinates(char *coor, int *i)
{
	int	index;
	int	delim;

	index = 0;
	delim = ',';
	while (coor && index < 3)
	{
		if (index == 2)
			delim = ' ';
		if (!parse_isfloat(coor, delim, i))
			return (0);
		if (coor[*i] == delim && index == 2)
			break ;
		*i += 1;
		index++;
	}
	return (1);
}

int	parse_isnormalvec(char *vec, int *i)
{
	int	index;
	int	start;
	int	col;
	int	delim;

	index = 0;
	delim = ',';
	while (vec && index < 3)
	{
		start = *i;
		if (index == 2)
			delim = ' ';
		if (!parse_isfloat(vec, delim, i))
			return (0);
		col = atofn(vec, *i - start);
		if (col < -1 || col > 1)
			return (0);
		*i += 1;
		index++;
	}
	return (1);
}
