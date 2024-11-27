/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_in_range.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/27 15:25:47 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <minirt.h>

// check if number is in range of min and max with float
int	parse_inrange_float(float min, float max, char *str, int *i)
{
	float	num;
	int		start;

	start = *i;
	if (!parse_isfloat(str, ' ', i))
		return (0);
	num = atofn(&str[start], *i - start);
	if (num < min || num > max)
		return (0);
	return (1);
}

// check if number is int like 10
int	parse_inrange_int(int min, int max, char *str, int *i)
{
	int		num;
	int		start;

	start = *i;
	if (!parse_isint(str, i))
		return (0);
	num = atoin(&str[start], *i - start);
	if (num >= min && num <= max)
		return (1);
	return (0);
}

int	parse_inrange_rgb_loop(int index, char *rgb, int check, int *i)
{
	while (index != 2)
	{
		if (rgb[*i] == ',')
			break ;
		if (!ft_isdigit(rgb[*i]))
			return (0);
		*i += 1;
	}
	while (index == 2)
	{
		if (!ft_isdigit(rgb[*i]))
			return (0);
		check++;
		*i += 1;
		if ((rgb[*i] == ' ' || rgb[*i] == '\n') && check)
			break ;
	}
	return (1);
}

int	parse_inrange_rgb(int min, int max, char *rgb, int *i)
{
	int	index;
	int	start;
	int	col;
	int	check;

	index = 0;
	check = 0;
	while (rgb && index < 3)
	{
		start = *i;
		if (!parse_inrange_rgb_loop(index, rgb, check, i))
			return (0);
		col = atoin(&rgb[start], *i - start);
		if (col < min || col > max)
			return (0);
		*i += 1;
		index++;
	}
	return (1);
}
