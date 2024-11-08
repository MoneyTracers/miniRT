/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/08 11:37:27 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

  
#include <parse.h>
#include <minirt.h>


t_tuple parse_get_coordinates(char *str, int *i)
{
	t_tuple tup;
	int	j;

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

	start = *i;
	while (!ft_isdigit(str[*i]))
	{
		if (str[*i] == '-')
		{
			*i += 1;
			break;
		}
		*i += 1;
	}
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
	if(ft_strncmp(num, "2147483647", *i - start) < 0)
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

int	parse_skipwhitespace(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

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
int	parse_isinrange_int(int min, int max, char *str, int* i)
{
	int		num;
	int		start;

	start = *i;
	if (!parse_isint(str, i))
		return (0);
	num = atoin(&str[*i], *i - start);
	if (num <= min || num >= max)
		return (1);
	return (0);
}

int parse_isrgb_inrange(int min, int max, char *rgb, int* i)
{
	int	index;
	int	start;
	int	col;

	index = 0;
	while (rgb && index < 3)
	{
		start = *i;
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
			if (rgb[*i] == ' ' || rgb[*i] == '\n')
				break ;
			if (!ft_isdigit(rgb[*i]))
				return (0);
			*i += 1;
		}
		col = atoin(&rgb[start], *i - start);
		if (col < min || col > max)
			return (0);
		*i += 1;
		index++;
	}
	return (1);
}

int parse_iscoordinates(char *coor, int *i)
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
			break;
		*i += 1;
		index++;
	}
	return (1);
}

int parse_isnormalvec(char *vec, int *i)
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

int	parse_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	debugger(MAG "%s:%d - %s\nopening file:\t%s\nfile fd:\t%d\n\n" RESET, __FILE__,__LINE__, __FUNCTION__ ,file, fd);
	if (fd == -1)
	{
		perror("unable to open file");
		exit(1);
	}
	return (fd);
}