/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_get.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/13 12:12:54 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <minirt.h>

t_tuple	parse_get_normal(char *str, int *i)
{
	t_tuple	tup;
	int		j;

	j = *i;
	j = parse_skipwhitespace(str, j);
	tup.w = 0;
	tup.x = parse_get_float(str, &j);
	j += 1;
	tup.y = parse_get_float(str, &j);
	j += 1;
	tup.z = parse_get_float(str, &j);
	j += 1;
	*i = j;
	return (tup);
}

t_tuple	parse_get_coordinates(char *str, int *i)
{
	t_tuple	tup;
	int		j;

	j = *i;
	j = parse_skipwhitespace(str, j);
	tup.w = 1;
	tup.x = parse_get_float(str, &j);
	j += 1;
	tup.y = parse_get_float(str, &j);
	j += 1;
	tup.z = parse_get_float(str, &j);
	j += 1;
	*i = j;
	return (tup);
}

t_color	parse_get_color(char *str, int *i)
{
	float	r;
	float	g;
	float	b;

	while (!ft_isdigit(str[*i]))
		*i += 1;
	r = parse_get_float(str, i);
	*i += 1;
	g = parse_get_float(str, i);
	*i += 1;
	b = parse_get_float(str, i);
	*i += 1;
	return (new_color(r, g, b));
}

float	parse_get_float(char *str, int *i)
{
	int	start;

	while (!ft_isdigit(str[*i]))
	{
		if (str[*i] == '-')
		{
			*i += 1;
			break ;
		}
		*i += 1;
	}
	start = *i;
	if (str[*i - 1] == '-')
		start = start - 1;
	while (ft_isdigit(str[*i]))
		*i += 1;
	if (str[*i] == '.')
	{
		*i += 1;
		while (ft_isdigit(str[*i]))
			*i += 1;
	}
	return (atofn(&str[start], *i - start));
}
