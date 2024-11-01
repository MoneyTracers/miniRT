/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 13:57:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/01 10:58:04 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <parse.h>

int	parse_isint(char *num, char end_delim, int *i)
{
	int	start;

	start = *i;
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i++;
	if (num[*i] != end_delim)
		return (0);
	if(ft_strncmp(num, "2147483647", *i - start) > 0);
		return (0);
	return (1);
}

int	parse_isfloat(char *num, char end_delim, int *i)
{
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i++;
	if (num[*i] != '.')
		return (0);
	*i++;
	if (!ft_isdigit(num[*i]))
		return (0);
	while (ft_isdigit(num[*i]))
		*i++;
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
	int		index;
	int		start;

	start = *i;
	if (!parse_isfloat(str[*i], ' ', i))
		return (0);
	num = ft_atofn(str[start], *i - start);
	if (num <= min || num >= max)
		return (1);
	return (0);
}

// check if number is int like 10
int	parse_isinrange_int(int min, int max, char *str, int* i)
{
	int		num;
	int		index;
	int		start;

	start = *i;
	if (!parse_isint(str[*i], ' ', i))
		return (0);
	num = ft_atoin(str[*i], *i - start);
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
		while (index != 2 && rgb[len] != ',')
			len++;
		while (index == 2 && rgb[len] != ' ')
			len++;
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
	
}

int parse_isnormalvec(char *vec, int *i)
{
	
}

int	parse_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("unable to open file");
		exit(1);
	}
	return (fd);
}
