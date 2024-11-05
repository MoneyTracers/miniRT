/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/05 16:57:47 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>
#include <minirt.h>


t_tuple parse_get_coordinates(char *str, int *i)
{
	t_tuple tup;

	*i = parse_skipwhitespace(str, *i);
	tup.w = 0;
	tup.x = parse_get_float(str, i);
	*i += 1;
	tup.y = parse_get_float(str, i);
	*i += 1;
	tup.z = parse_get_float(str, i);
	*i += 1;
	return (tup);
}

t_color parse_get_color(char *str, int *i)
{
	float r;
	float g;
	float b;

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

float parse_get_float(char *str, int *i)
{
	int	start;

	while (!ft_isdigit(str[*i]))
	{
		if (str[*i] == '-')
			break;
		*i += 1;
	}
	start = *i;
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

int	parse_isint(char *num, char end_delim, int *i)
{
	int	start;

	start = *i;
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (num[*i] != end_delim)
		return (0);
	if(ft_strncmp(num, "2147483647", *i - start) > 0)
		return (0);
	return (1);
}

int	parse_isfloat(char *num, char end_delim, int *i)
{
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (num[*i] != '.')
		return (0);
	*i += 1;
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i += 1;
	if (num[*i] != end_delim)
		return (0);
	return (1);
}

int	parse_skipwhitespace(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

// check if number is in range of min and max with float
int	parse_inrange_float(double min, double max, char *str, int *i)
{
	double	num;
	int		start;

	start = *i;
	if (!parse_isfloat(&str[*i], ' ', i))
		return (0);
	num = atofn(&str[start], *i - start);
	if (num <= min || num >= max)
		return (1);
	return (0);
}

// check if number is int like 10
int	parse_isinrange_int(int min, int max, char *str, int* i)
{
	int		num;
	int		start;

	start = *i;
	if (!parse_isint(&str[*i], ' ', i))
		return (0);
	num = atoin(&str[*i], *i - start);
	if (num <= min || num >= max)
		return (1);
	return (0);
}

int parse_isrgb_inrange(int min, int max, char *rgb, int* i)
{
	int	index;
	int	len;
	int	col;

	index = 0;
	len = 0;
	while (rgb && index < 3)
	{
		len = 0;
		while (index != 2)
		{
			if (rgb[len] == ',')
				break ;
			if (!ft_isdigit(rgb[len]))
				return (1);
			len++;
		}
		while (index == 2)
		{
			if (rgb[len] == ' ')
				break ;
			if (!ft_isdigit(rgb[len]))
				return (1);
			len++;
		}
		col = atoin(rgb, len);
		if (col <= min || col >= max)
			return (1);
		*i += len;
		rgb += len;
		index++;
	}
	return (0);
}

int parse_iscoordinates(char *coor, int *i)
{
	int	index;
	int	len;
	int	col;
	int	delim;

	index = 0;
	len = 0;
	delim = ',';
	while (coor && index < 3)
	{
		len = 0;
		if (index == 2)
			delim = ' ';
		while (index != 2)
		{
			if (coor[len] == delim)
				break ;
			if (!ft_isdigit(coor[len]))
				return (1);
			len++;
		}
		col = atofn(coor, len);
		*i += len;
		coor += len;
		index++;
	}
	return (0);
}

int parse_isnormalvec(char *vec, int *i)
{
	int	index;
	int	len;
	int	col;
	int	delim;

	index = 0;
	len = 0;
	delim = ',';
	while (vec && index < 3)
	{
		len = 0;
		if (index == 2)
			delim = ' ';
		while (index != 2)
		{
			if (vec[len] == delim)
				break ;
			if (!ft_isdigit(vec[len]))
				return (1);
			len++;
		}
		col = atofn(vec, len);
		if (col < -1 || col > 1)
			return (1);
		*i += len;
		vec += len;
		index++;
	}
	return (0);
}

int	parse_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	debugger(MAG "%s:%s:%d\nopening file:\t%s\nfile fd:\t%d\n" RESET, __FILE__, __FUNCTION__ ,__LINE__,file, fd);
	if (fd == -1)
	{
		perror("unable to open file");
		exit(1);
	}
	return (fd);
}
